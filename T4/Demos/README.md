# T4 — Assertions, Exceptions & Smart Pointers

One runnable demo per Vevox poll question discussed in the tutorial related to `Module 7 — Assertions, Exceptions & Smart Pointers`.
Each demo folder has its own `README.md` with the build command, expected output, and the subfolders with the code files.

**Code Subfolders:**
- `clean/` = what students should look at first (bug preserved, poll question + full multiple-choice options in a header comment)
- `commented/` = same code with comments pointing towards the solution discussed in class
- `solution/` = the fix (omitted for the observation demos 06 & 11)
- `pitfall_*/` = an instructive variant (not all topics have one)

## Poll-Demo Relationship

*Folder numbers match station numbers; some stations have two poll questions.*

| # | Challenge | Vevox Question | Code subfolder | Result |
|---|-----------|----------------|----------------|--------|
| Q1.1 | Assertions | A release build (`-DNDEBUG`) of `assert(i++ == 10)` prints? | [01_assertions](01_assertions/) `clean/main.cpp` | `i = 10` => `NDEBUG` drops the assert *and* the hidden `i++` |
| Q1.2 | Assertions (concept) | When is `assert` the right tool, not a throw? | [01_assertions](01_assertions/) (concept) | A private helper called with a value your own code should never produce |
| Q2.1 | Throw a typed object | `throw "..."` caught by `catch(const std::exception&)`. What happens? | [02_throw_typed](02_throw_typed/) `clean/main.cpp` | `std::terminate` => `const char*` doesn't match (no conversions) |
| Q3.1 | Catch by value | Catching `std::exception` **by value** prints? | [03_catch_by_value](03_catch_by_value/) `clean/main.cpp` | `std::exception` => slicing drops the real message |
| Q4.1 | Handler order | The base handler is listed before the derived one. What happens? | [04_catch_order](04_catch_order/) `clean/main.cpp` | Warns, prints `general handler` (the derived clause is dead code) |
| Q5.1 | Rethrow | `throw e;` (not `throw;`) of a `Derived` caught as `Base&`. What's the output? | [05_rethrow](05_rethrow/) `clean/main.cpp` | `inner`, then terminate => `throw e;` slices to `Base` |
| Q6.1 | Construction throws | `c` throws mid-construction => which destructors run? | [06_construction_throws](06_construction_throws/) `clean/main.cpp` | `ctor 0/1/2 => dtor 1/0 => caught: boom` (`~c` skipped) |
| Q7.1 | Raw-pointer leak | `doWork()` throws => does `Resource freed` print? | [07_raw_pointer_leak](07_raw_pointer_leak/) `clean/main.cpp` | No, `delete` is skipped, the heap Resource leaks |
| Q8.1 | Exception safety | Frozen `bob`; after the failed transfer, what is `alice + bob`? | [08_exception_safety](08_exception_safety/) `clean/main.cpp` | `0` => money left alice, never reached bob (not basic-safe) |
| Q9.1 | `unique_ptr` (copy) | `auto q = p;` on a `unique_ptr` => what happens? | [09_unique_ptr_move](09_unique_ptr_move/) `clean/main.cpp` | Compile error => the copy ctor is deleted; use `std::move` |
| Q9.2 | `unique_ptr` (move) | After `auto q = std::move(p)`, what does `p` print? | [09_unique_ptr_move](09_unique_ptr_move/) `solution/main.cpp` | `p null` => moving a `unique_ptr` empties the source |
| Q10.1 | `shared_ptr` cycle | A and B co-own each other via `shared_ptr` => what prints? | [10_shared_ptr_cycle](10_shared_ptr_cycle/) `clean/main.cpp` | `end of main` only => reference cycle, neither dtor runs |
| Q11.1 | RAII | Does `File closed` print, and when? | [11_raii_file](11_raii_file/) `clean/main.cpp` | Yes, `~File` runs during unwinding, *before* `caught` |
| Q12.1 | `noexcept` | A `noexcept` function throws => what does it print? | [12_noexcept_terminate](12_noexcept_terminate/) `clean/main.cpp` | Nothing => `std::terminate`; the `catch` is bypassed |
| Q12.2 | `noexcept` (concept) | Which case does NOT call `std::terminate` (C++17)? | [12_noexcept_terminate](12_noexcept_terminate/) (concept) | A `runtime_error` caught by `catch(const std::exception&)` |
| Q13.1 | pImpl `Rational` (dtor) | The header declares no `~Rational()`; you build => what happens? | [13_rational_pimpl](13_rational_pimpl/) `pitfall_incomplete_type/` | Compile error in main's TU => can't delete the incomplete `Impl` |
| Q13.2 | pImpl `Rational` (move) | `report("ar", ar)` after `at(std::move(ar))` prints? | [13_rational_pimpl](13_rational_pimpl/) `clean/main.cpp` | `ar is unbound` => the move left `ar` null |

## Caveats that might change a poll answer

- **Q1.1:** the answer flips by build => debug (no `-DNDEBUG`) prints `i = 11`, release (with `-DNDEBUG`) prints `i = 10`. Same source, two answers.
- **Q3.1 / Q4.1 / Q12.1:** g++ and clang differ on which `-W` warning fires (`-Wcatch-value`, `-Wexceptions`, `-Wterminate`), but all still build.
- **Leaks (Q7.1, Q10.1):** `valgrind`/ASan leak-detection isn't available on ARM Macs => read the missing-destructor line as the leak, or run the check on the Linux servers. `g++ -g` leaves a `.dSYM` bundle.
