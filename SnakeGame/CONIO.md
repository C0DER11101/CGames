# The problem that I faced with `conio.h`
When you open `conio.h` header file, you will find that it contains `class` definitions which is not supported by C and so I got the following errors:

<img src="https://user-images.githubusercontent.com/96164229/246372964-7953d743-4846-48ec-853d-a6993a7631be.png" width="60%" height="60%">

So, I ended up modifying `conio.h` by removing the class definitions and replacing them by `struct`, the rest of everything is kept the same and I renamed it `Co.h`(that's why my files have the header `Co.h`).


<p align="center">
&#9678; &#9678; &#9678;
</p>
