# Rectangle into Squares

The drawing below gives an idea of how to cut a given "true" rectangle into squares ("true" rectangle meaning that the two dimensions are different).

![Picture](./picture.jpg)

Can you translate this drawing into an algorithm?

You will be given two dimensions

1. a positive integer length (parameter named lng)
1. a positive integer width (parameter named wdth)

```
  sqInRect(5, 3) should return [3, 2, 1, 1]
  sqInRect(3, 5) should return [3, 2, 1, 1]
  or (Haskell)
  squaresInRect  5  3 `shouldBe` Just [3,2,1,1]
  squaresInRect  3  5 `shouldBe` Just [3,2,1,1]
  or (Fsharp)
  squaresInRect  5  3 should return Some [3,2,1,1]
  squaresInRect  3  5 should return Some [3,2,1,1]
  or (Swift)
  squaresInRect  5  3 should return [3,2,1,1] as optional
  squaresInRect  3  5 should return [3,2,1,1] as optional
  or (Cpp)
  sqInRect(5, 3) should return {3, 2, 1, 1}
  sqInRect(3, 5) should return {3, 2, 1, 1}
  (C)
  C returns a structure, see the "Solution" and "Examples" tabs.
  Your result and the reference test solution are compared by strings.
```

You will return an array or a string (depending on the language; Shell bash and Fortran return a string) with the size of each of the squares.

Notes:

* lng == wdth as a starting case would be an entirely different problem and the drawing is planned to be interpreted with lng != wdth. (See kata, Square into Squares. Protect trees! http://www.codewars.com/kata/54eb33e5bc1a25440d000891 for this problem).

* When the initial parameters are so that lng == wdth, the solution [lng] would be the most obvious but not in the spirit of this kata so, in that case, return None/nil/null/`Nothing

* return {} with C++, Array() with Scala.

* In that case the returned structure of C will have its sz component equal to 0.

* Return the string "nil" with Bash and Fortran.


# Template
```C++

#include <vector>

class SqInRect
{
  public:
  static std::vector<int> sqInRect(int lng, int wdth);
};


```

# Source:
https://www.codewars.com/kata/rectangle-into-squares/train/cpp
