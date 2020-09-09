# Gel Auto Dispenser

## Parts
- arduino nano (5v)
- mg995 servo (5v)
- hc-sr04 or us-025 ultrasonic sensor (3v/5v)
- 6v psu (my servo doesn't work with enough strength in 5v)
- 3d printed models
- one recycled liquid soap dispenser


## Wiring
- D6 -> SERVO INPUT
- D7 -> US-025 ECHO PIN
- D8 -> US-025 TRIGGER PIN
- 3v -> US-025 VIN
- GND -> US-025 GND

- 6v -> NANO VIN and SERVO VIN
- GND -> NANO GND and SERVO GND

## Notes
My servo was is from az-delivery brand, and they recommend these Servo.h (located on `libraries/Servo/src`) settings:

```
#define Servo_VERSION           2     // software version of this library

#define MIN_PULSE_WIDTH       500     // 544 era el valor orignal. the shortest pulse sent to a servo  
#define MAX_PULSE_WIDTH      2500     // 2400 era el valor original. the longest pulse sent to a servo 
#define DEFAULT_PULSE_WIDTH  1500     // default pulse width when servo is attached
#define REFRESH_INTERVAL    20000     // minumim time to refresh servos in microseconds 

#define SERVOS_PER_TIMER       12     // the maximum number of servos controlled by one timer 
#define MAX_SERVOS   (_Nbr_16timers  * SERVOS_PER_TIMER)

#define INVALID_SERVO         255     // flag indicating an invalid servo index
```
