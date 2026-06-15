# T1 — ADT Design

One runnable demo per Vevox poll question discussed in the tutorial related to `Module 2 — ADT Design`. 
Each demo folder has its own `README.md` with the build command, expected output, and the subfolders with the code files.

**Code Subfolders:** 
- `clean/` = what students should look at first (bug preserved, poll question in a header comment)
- `commented/` = same code with comments pointing towards the solution discussed in class 
- `solution/` = the fix 
- `pitfall_*/` = an instructive variant (not all topics have one)

## Poll-Demo Relationship


| # | Challenge | Vevox Question | Code subfolder | Result |
|---|----------------------|--------------|-------------|--------|
| 1 | ADT Motivation | Do negative IDs, ID arithmetic, and swapped args compile? | [01_adt_motivation](01_adt_motivation/) | Yes, they do. `typedef` catches nothing; compiles, silently wrong |
| 2 | MIL | What is the value of `result_` after `Tricky t(5)`? | [02_member_init_list](02_member_init_list/) | Garbage. `result_` is not `10`. Members init in **declaration** order, not MIL order (**UB**) |
| 3 | Constant Member Functions | Can a `const` method modify a member variable? | [03_const_member_functions](03_const_member_functions/) | Yes, if it's `mutable`; no-`mutable` variant errors |
| 4 | Function Overloading | Can two functions differ only in return type? | [04_function_overloading_return_type](04_function_overloading_return_type/) | No => **compile error** |
| 5 | Default Arguments | How do default arguments interact with implicit conversion? | [05_default_args_implicit_conversion](05_default_args_implicit_conversion/) | `print(5)` => silent `Rational(5,1)` => **no warning** |
| 6 | Default Arguments – Challenge 2 | What is the difference between `()` and `{}` when calling an explicit constructor? | [06_brace_vs_paren_narrowing](06_brace_vs_paren_narrowing/) ⚠ | `{}` clang error / **g++ warning**; `()` silently truncates to `2/1` |
| 7 | Operator Overloading | The Post-Increment Lie: what do `old` and `m` print? | [07_operator_overloading_post_increment](07_operator_overloading_post_increment/) | Both `3/1` => the old value was never saved (**silently wrong**) |
| 8 | Streaming Operators | What does returning `void` from `operator<<` break? | [08_streaming_operators_void_return](08_streaming_operators_void_return/) | Chaining => **compile error** |
| 9 | Type Conversion and explicit | What does `1` silently become without `explicit`? | [09_type_conversion_explicit](09_type_conversion_explicit/) | `Rational(1)` => `r == 1` compares `3/4 == 1/1` => **no warning** |
| 10 | Friends | Can a friend function bypass the constructor's invariant check? | [10_friends_break_invariant](10_friends_break_invariant/) | Yes, writes `denom_ = 0` past the check => runs => `2/0` |
| 11 | Helper Functions | What happens when two `.cc` files define the same free function name? | [11_helper_functions_multiple_definition](11_helper_functions_multiple_definition/) | **Linker error** (multiple definition) |
| 12 | override and final | What does missing `virtual` on the destructor actually cost you? | [12_override_final_virtual_destructor](12_override_final_virtual_destructor/) | `~Dog()` skipped on `delete` via `Animal*`, leak => silent |

## Caveats that might change a poll answer

- **Demo 06:** `m{2.3}` is a hard error on clang, but on **g++/Linux**  narrowing in `{}` is only a `-Wnarrowing` **warning** => it still compiles and truncates to `2/1`. Add `-Werror=narrowing` to enforce the behavior.
- **Demo 02:** `result_` is indeterminate (UB) => no fixed value can be guaranteed.
- **Demo 12:** the leak is fully silent; `-Wall` does **not** warn (Animal is non-polymorphic) => be aware and careful with such behavior.
- **Demos 05 & 09:** the silent `int => Rational` conversions produce **no** diagnostic even at `-Wall -Wextra` => be aware and careful with such behavior.

