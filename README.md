# ChaCha20 Chipwhisperer

- Max Boone (s2081318)
- Sven Hepkema (s2454556)
- Guus Kleinlein (s3745880)

## Project

In the `books` folder you will find the notebooks used to execute
the attack. In `include` and `lib` you will find the library code
used to build the algorithms for the ChipWhisperer.

## Building

The firmware can be built using the `Makefile` in the root of the repository:

```bash
make ALGO=shiffthq PLATFORM=CWLITEARM SS_VER=SS_VER_1_1
make ALGO=mbedtls PLATFORM=CWLITEARM SS_VER=SS_VER_1_1
``` 

## Flashing

Use the `flash-and-measure.ipynb` to flash and run the algorithm and traces,
ensure to set the correct variables in the top cells for your platform and algorithm
and use the necessary `run_many_traces` calls at the bottom of the book.

## Attack Analysis

Use the `attack-$algo-$traces.ipynb` notebooks to execute the correlation analysis,
note that this will take quite some time and memory on larger traces.