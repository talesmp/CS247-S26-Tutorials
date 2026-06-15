# T2 — Object Types & Special Member Functions

One runnable demo per Vevox poll question discussed in the tutorial related to `Modules 3 & 4 — Object Types & Special Member Functions`.
Each demo folder has its own `README.md` with the build command, expected output, and the subfolders with the code files.

**Code Subfolders:**
- `clean/` = what students should look at first (bug preserved, poll question in a header comment)
- `commented/` = same code with comments pointing towards the solution discussed in class
- `solution/` = the fix
- `pitfall_*/` = an instructive variant (not all topics have one)

## Poll-Demo Relationship

| # | Challenge | Vevox Question | Code subfolder | Result |
|---|-----------|----------------|----------------|--------|
| 1 | Entity Objects | Will this compile, and if so, what does it print? | [01_entity_no_pass_by_value](01_entity_no_pass_by_value/) | No, deleting copy => move also gone; can't pass by value (**compile error**) |
| 2 | Value Objects | What does this print? | [02_value_implicit_conversion](02_value_implicit_conversion/) | `five dollars` => silent `int => Money` (`pitfall_typo` = silent wrong answer) |
| 3 | Mutable vs. Immutable | Will this compile? If so, what does the second print show? | [03_immutable_const_cast_leak](03_immutable_const_cast_leak/) | `1 2 3 99` => `const_cast` mutates it (`pitfall_const_object` = real UB) |
| 4 | Singleton | What is the value of `Egg::instance()->val()` printed at the end? | [04_singleton_init_order](04_singleton_init_order/) | **100 or 42** => static-init-order fiasco, by link order |
| 5 | PImpl Idiom | Will this header-only pImpl class compile when a client writes `Widget w;`? | [05_pimpl_incomplete_type](05_pimpl_incomplete_type/) | No, `~Widget()` emitted where `Impl` is incomplete (**compile error**) |
| 6 | Default Constructor | What is the value of `m.p.x` at the assert? | [06_default_ctor_uninitialized](06_default_ctor_uninitialized/) | Indeterminate => `p` left uninitialized => assert UB |
| 7 | Destructor | How many `C` destructors run by the time main returns? | [07_destructor_raw_pointer_leak](07_destructor_raw_pointer_leak/) | Zero => raw owning pointer never deleted => leak (no `C dtor`) |
| 8 | Copy Constructor | What does this print? | [08_copy_ctor_shallow_double_free](08_copy_ctor_shallow_double_free/) | UB => shallow copy => use-after-free + double free |
| 9 | Copy Assignment | What does this print? | [09_copy_assign_self_assignment](09_copy_assign_self_assignment/) | UB on `a = a` => `delete` then read the freed source |
| 10 | Copy-Swap Idiom | Does this `operator=` correctly implement copy-and-swap? | [10_copy_swap_by_value](10_copy_swap_by_value/) | Correct, but suboptimal => `const&` always copies; take by value |
| 11 | lvalue vs. rvalue | Which constructor of `Widget` runs on the marked line? | [11_lvalue_named_rvalue_ref](11_lvalue_named_rvalue_ref/) | Copy => a named `Widget&&` is an lvalue |
| 12 | Move Constructor | Why is the move constructor never called? | [12_move_ctor_suppressed_by_dtor](12_move_ctor_suppressed_by_dtor/) | User `~Big(){}` suppresses the implicit move => copies |
| 13 | Move Assignment | What is the value of `*a.data_` at the end? | [13_move_assign_leaks_old](13_move_assign_leaks_old/) | `2`, but a's old int leaks; no self-move guard |
| 14 | Copy/Move Elision | Which constructors run when `v` is initialized? | [14_elision_pessimizing_move](14_elision_pessimizing_move/) | Default + move => `return std::move(local)` blocks NRVO (**`-Wpessimizing-move`**) |
| 15 | Rule of Five table | Does this compile, and which constructor runs at the marked line? | [15_rule_of_five_move_deletes_copy](15_rule_of_five_move_deletes_copy/) | No, declaring move deletes the copy ctor (**compile error**) |
| 16 | Equality Operator | What does this print? | [16_equality_compares_pointers](16_equality_compares_pointers/) | `different` => `operator==` compares addresses, not values |

## Caveats that might change a poll answer

- **Demo 04:** the `100`-vs-`42` outcome is unspecified, decided by **link order** => flip it by reordering the `.cpp` files. Inherent to cross-TU static init.
- **Demo 06:** `m.p.x` is indeterminate (UB) => the assert reliably fires on ARM-based Macs (junk value), but a lucky run could read `0`. A lucky pass isn't safety.
- **Demos 08 & 09:** ASan catches the use-after-free / double-free on arm64, but LSan leak detection does **not** => run `valgrind ./app` on the Linux servers.
- **Demo 09:** clang `-Wall` warns on `a = a` (`-Wself-assign-overloaded`); **g++ has no equivalent** => silent until valgrind.
- **Demos 07 & 13:** the leaks are silent on ARM-based Macs (no valgrind/LSan) => read the missing `dtor`/`delete`, or run `valgrind ./app` on the Linux servers.
