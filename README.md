# SNAP Standard Library v1.0

**Author:** Andre Gray  
© Andre Gray 2008  

**Purpose:** Minimal standard library of DSP building blocks for SNAP.

The SNAP Standard Library provides essential **unit generators (UGens)** for synthesizer programming:

- Oscillators: `SineOsc`
- Filters: `OnePoleLP` low-pass filter
- Envelope: `ADSR` amplitude envelope
- Utilities: ready for mixers, panning, etc.

---

## Directory Structure
snap-stdlib/
├── include/
│ ├── osc.h
│ ├── filter.h
│ └── envelope.h
├── CMakeLists.txt
└── examples/
└── test.cpp

## Notes

- All code is C++03-compliant for maximum portability.
- Intended as the core DSP library for SNAP compiler and future SNAP projects.
- Can be extended to include additional oscillators, filters, ADSR variations, mixers, and utilities.
