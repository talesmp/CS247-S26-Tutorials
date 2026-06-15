# T3 — Modules & Interface Specifications

One runnable demo per Vevox poll question discussed in the tutorial related to `Modules 5 & 6 — Modules, Interface Specifications & Makefiles`.
Each demo folder has its own `README.md` with the build command, expected output, and the subfolders with the code files.

**Code Subfolders:**
- `clean/` = what students should look at first (bug preserved, poll question + full multiple-choice options in a header comment)
- `commented/` = same code with comments pointing towards the solution discussed in class
- `solution/` = the fix (some demos use `solution_*/` variants; `03` & `07` have none; `08_makefile` is a single project)
- `pitfall_*/` = an instructive variant (not all topics have one)

## Poll-Demo Relationship

*Poll question numbers do **not** match folder numbers (e.g. Q7.1 => folder `03`); use the table.*

| # | Challenge | Vevox Question | Code subfolder | Result |
|---|-----------|----------------|----------------|--------|
| Q1.1 | Separate compilation | `B` is declared in `ADT1.h`, defined in `ADT1.cpp`; you build `g++ ADT1.cpp main.cpp`. What happens? | [01_separate_compilation](01_separate_compilation/) `clean/main.cpp` | Compiler error: `'B' was not declared` (main.cpp never includes the header) |
| Q2.1 | Linkage (`static`) | The `static` counter builds and links. What prints? | [02_decl_vs_def_linkage](02_decl_vs_def_linkage/) `pitfall_static/` | `main's counter = 5; counter = 0` (each TU gets its own copy) |
| Q2.2 | Linkage (`const`) | A global in a header `#include`d by 6 `.cpp` files: which version link-errors? | [02_decl_vs_def_linkage](02_decl_vs_def_linkage/) (conceptual) | Only `int MAX` (external linkage); `const int` defaults to internal |
| Q3.1 | Header guards | `widget.h` has no guard and is included twice. What happens? | [04_header_guards](04_header_guards/) `clean/main.cpp` | Compiler error: redefinition of `class Widget` |
| Q4.1 | Preprocessor macros | What does `SQUARE(2 + 3)` print? | [06_preprocessor_macros](06_preprocessor_macros/) `clean/macros.cpp` | `11` => text substitution: `2 + 3*2 + 3` |
| Q5.1 | Circular includes | Two guarded headers include each other. What happens? | [05_circular_forward_decl](05_circular_forward_decl/) `clean/main.cpp` | Compile error: a class used before it's declared (guards ≠ forward decl) |
| Q6.1 | Build pipeline | Is `g++ -c hello.cpp` successful even though `std::cout` lives in a library? | [07_build_pipeline](07_build_pipeline/) `clean/hello.cpp` | Yes, `-c` compiles+assembles only; library symbols resolve at link |
| Q7.1 | Undefined reference | All code is correct, but the build forgets `mathutil.cpp`. What happens? | [03_undefined_reference](03_undefined_reference/) `clean/main.cpp` | Linker error: undefined reference to `square(int)` |
| Q8.1 | Makefile (timestamps) | You touch `vec.h` and run `make`. What happens? | [08_makefile](08_makefile/) `Makefile` | Every `.o` that includes it recompiles, then re-links (timestamps, not contents) |
| Q8.2 | Makefile (TAB) | The recipe is indented with spaces, not a TAB. What prints? | [08_makefile](08_makefile/) `Makefile.broken` | `*** missing separator. Stop.` |
| Q9.1 | Contract (precondition) | What happens with `quotientPre(10, 0)`? | [09_contract_requires_vs_throws](09_contract_requires_vs_throws/) `clean/contracts.cpp` | It depends on the machine (UB: x86 traps, ARM returns 0) |
| Q9.2 | Contract (return) | What does `indexOf` do when the value is absent? | [09_contract_requires_vs_throws](09_contract_requires_vs_throws/) `clean/contracts.cpp` | A garbage number, may look plausible (falls off a non-void function => UB) |
| Q10.1 | Spec fields (derived) | fee 30, freemin 200, rate 1. What is the 2nd balance? | [10_spec_fields_derived](10_spec_fields_derived/) `clean/main.cpp` | `410` => `bill()` never resets `minutes` (should be 160) |
| Q11.1 | Specificand set (`findA`) | What does `findA` do on an absent value? | [11_specificand_set_find](11_specificand_set_find/) `clean/find.cpp` | UB => reads past the end (garbage or crash) |
| Q11.2 | Specificand set (A/B/C) | Which of A/B/C meet "an index of `val`, else −1"? | [11_specificand_set_find](11_specificand_set_find/) (conceptual) | Only B (A is UB if absent; C returns size, not −1) |
| Q12.1 | Tooling (gdb) | gdb stops with `found == 0x0`. Where is the bug? | [12_tooling](12_tooling/) `clean/buggy.cpp` | Upstream => the caller never checked `findFirst` returned `nullptr` |
| Q13.1 | Tooling (valgrind) | Crash fixed, exits 0, tests pass. Is it memory-clean? | [12_tooling](12_tooling/) `clean/buggy.cpp` | No, `new[]` with no `delete[]` leaks (valgrind would find it) |

## Caveats that might change a poll answer

- **Compiler wording:** the course environment is **g++ on Linux**; on a Mac, `g++` is usually Apple Clang => same error *category*, different wording (e.g. linker: g++ "multiple definition" vs macOS "duplicate symbol").
- **Q9.1 & Q13.1:** genuinely platform-dependent => integer ÷0 is UB that traps on x86 but returns 0 on ARM, and `valgrind` runs on the Linux servers, not macOS.
