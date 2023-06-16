# Problems with the game
When I first ran the game, the snake ate the food and its length was increased without any problem, but when the snake ate the food the second time, notice in the images below, its coordinates changed horribly:

<img src="https://user-images.githubusercontent.com/96164229/246375118-605c3343-be61-498f-8c91-a41654714ed0.png" width="60%" height="60%">


<img src="https://user-images.githubusercontent.com/96164229/246375211-512062a0-a188-4a46-bc48-f7d87b56f94d.png" width="60%" height="60%">

Also, I got a core-dumped message like this:

<img src="https://user-images.githubusercontent.com/96164229/246375286-b3235cdf-4a10-4972-b8c0-5bf6c86d9296.png" width="60%" height="60%">

Now this kind of message is generally shown when we try to free an already freed memory block, but I had not freed any memory until the user pressed `e` or the snake hit the borders or bit itself. Then why this message?

Well, I found the solution to this problem [here](https://help.totalview.io/classicTV/current/HTML/index.html#page/User_Guides/reallocProblems.html#ww1162641).

It said here that the `realloc()` function can either extend a current memory block, or create a new block and **free the old**. In my case, I am assuming that `realloc` created a new block and freed the old block when the snake ate the food the second time, and that's why the shifting operation `grow()` didn't work properly and I got those garbage values for the x and y coordinates.

Now, it works, I replaced the definition `snake*hissy;` with `snake hissy[100];`


<p align="center">
&#9678; &#9678; &#9678;
</p>
