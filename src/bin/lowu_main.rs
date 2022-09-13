#![no_main]
#![no_std]

use lowu as _; // global logger + panicking-behavior + memory layout

#[rtic::app(
    device = stm32wlxx_hal::pac, // TODO: Replace `some_hal::pac` with the path to the PAC
//    dispatchers = [FreeInterrupt1, ...] // TODO: Replace the `FreeInterrupt1, ...` with free interrupt vectors if software tasks are used
)]
mod app {
    use stm32wlxx_hal::{rcc, pac::{self, USART1}, uart::{self, Uart1, NoRx}, gpio::{pins, PortB}};
    use cortex_m::prelude::_embedded_hal_serial_Write;

    // TODO: Add a monotonic if scheduling will be used
    // #[monotonic(binds = SysTick, default = true)]
    // type DwtMono = DwtSystick<80_000_000>;

    // Shared resources go here
    #[shared]
    struct Shared {
        // TODO: Add resources
    }

    // Local resources go here
    #[local]
    struct Local {
        
        // TODO: Add resources
    }

    #[init]
    fn init(cx: init::Context) -> (Shared, Local, init::Monotonics) {
        let mut dp = cx.device;

        let cs = unsafe { &cortex_m::interrupt::CriticalSection::new() };
        unsafe {
            rcc::set_sysclk_msi(
                &mut dp.FLASH,
                &mut dp.PWR,
                &mut dp.RCC,
                rcc::MsiRange::Range48M,
                cs,
            )
        };
        
        dp.RCC.cr.modify(|_, w| w.hsion().set_bit());
        while dp.RCC.cr.read().hsirdy().is_not_ready() {}

        let gpiob: PortB = PortB::split(dp.GPIOB, &mut dp.RCC);
        let mut uart: Uart1<pins::B7, pins::B6> = Uart1::new(dp.USART1, 115200, uart::Clk::Hsi16, &mut dp.RCC).enable_tx(gpiob.b6, cs).enable_rx(gpiob.b7, cs);
        cortex_m::prelude::_embedded_hal_serial_Write::write(&mut uart, 85);
        defmt_serial::defmt_serial(uart);

        defmt::warn!("init");


        // task1::spawn().ok();

        // Setup the monotonic timer
        (
            Shared {
                
                // Initialization of shared resources go here
            },
            Local {
            },
            init::Monotonics(
                // Initialization of optional monotonic timers go here
            ),
        )
    }

    #[idle]
    fn idle(ctx: idle::Context) -> ! {
        defmt::info!("idle");

        loop {
            continue;
        }
    }

    // TODO: Add tasks
    // #[task]
    // fn task1(_cx: task1::Context) {
    //     defmt::info!("Hello from task1!");
    // }
}
