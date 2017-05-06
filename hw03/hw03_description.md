

<body>


<center>
<h2>DSA Homework 3</h2>
</center>



<h3 align=center><font color=green>2048 (DFS using a stack)</font></h3>



Outlines
<ul>
<li><a href=index.asp#problemDefinition>Problem definition</a>
<li><a href=index.asp#suggestedApproach>Suggested approach</a>
<li><a href=index.asp#inputOutputFormat>Input/output formats</a>
<li><a href=index.asp#requirement>Requirements</a>
<li><a href=index.asp#dataset>Datasets</a>
</ul>

<a name=problemDefinition></a>
<h4>Problem definition</h4>

<p>2048 has been a popular game since its debut in March, 2014. <p>Before you start, you should get familiar with the game. Here is some references:
<ul>
<li>Test drive the game: <a href="http://2048game.com">http://2048game.com</a>
<li>Wiki: <a href="https://en.wikipedia.org/wiki/2048_(video_game)">English</a>, <a href="https://zh.wikipedia.org/wiki/2048">Chinese</a>
</ul>

In this homework, your mission is to write a program to identify an action sequence (consisting of the four actions of east, south, west, north) that can lead the game from its initial map to its desirable final map of at least one element of 2048.

<a name=suggestedApproach></a>
<h4>Suggested approach</h4>

<p>As instructed in the class, you can use stack-based DFS (depth-first search) to find the action sequence. For details, please refer to the <a href="/jang/courses/dsa/slide/2048.ppt">slides</a> and <a href="http://u.camdemy.com/media/12073">recording</a> of our coverage of the homework.

<p>On the other hand, if you prefer, you can also use recursive backtracking (which uses an implicit stack) to achieve the same goal. (Try google.)

<a name=inputOutputFormat></a>
<h4>Input/output formats</h4>
<p>In an input file, the first line is N, the number of cases of 2048 game for your program to run. And each 4 following lines is an initial map for 2048 game. In other words, there should be 4*N+1 lines in an input file. For example, the following input file has N=10:<br>

10<br>
0 4 2 2<br>
2 0 0 2<br>
0 0 2 0<br>
4 0 2 0<br>
0 2 0 2<br>
2 0 4 2<br>
0 0 0 16<br>
16 0 0 2<br>
0 2 32 4<br>
8 4 16 0<br>
0 0 0 0<br>
2 0 0 0<br>
2 0 0 0<br>
0 0 2 0<br>
0 4 2 0<br>
0 2 16 2<br>
0 0 0 64<br>
2 4 0 0<br>
0 0 8 0<br>
16 0 0 16<br>
2 0 64 4<br>
0 0 2 2<br>
2 0 2 0<br>
2 4 8 2<br>
0 0 0 4<br>
2 0 0 0<br>
2 0 2 0<br>
0 2 0 2<br>
16 2 0 2<br>
4 0 0 2<br>
4 0 0 0<br>
4 0 2 8<br>
0 2 32 8<br>
0 0 2 0<br>
2 2 0 4<br>
4 0 0 0<br>
1024 4 1024 2<br>
4 8 4 8<br>
64 32 64 32<br>
4 2 4 2<br>


<p>For each case, you need to identify the action sequence to generate the final map. If you can find an action sequence to reach the final map (with at least one element of 2048), you should print the action sequence as well as the final map. For instance, a typical output for the first case of the above input file is shown next. (Note that the action and the final map may not be unique.)

Action:<br>
0 0 0 0 0 0 0 0 0 0 0 0 0 1 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 1 0 0 0 0 0 0 0 0 0 0 0 0 0 0 1 1 0 0 0 1 0 0 1 0 0 0 1 0 0 0 0 0 0 0 1 0 1 0 1 0 0 1 2 0 3 0 0 1 0 0 0 0 0 0 1 0 1 0 0 1 1 3 0 1 0 0 0 0 0 0 0 0 0 0 0 0 0 0 1 0 0 0 1 2 0 1 0 0 0 0 0 0 0 0 0 0 0 0 1 0 1 1 0 0 1 1 1 1 3 0 0 0 0 0 0 0 1 1 1 2 1 0 0 1 0 1 0 1 0 0 0 0 1 2 0 1 0 1 0 0 1 0 0 0 1 0 0 0 0 0 2 1 0 0 0 0 0 0 1 0 0 0 0 0 1 0 1 0 0 0 0 1 0 0 0 1 0 0 0 0 0 0 1 0 1 0 0 3 0 0 0 1 0 1 1 1 0 1 2 0 1 0 1 0 0 0 0 0 0 1 0 0 0 0 0 0 1 0 1 2 0 1 0 1 2 0 1 0 0 1 0 1 0 0 0 0 0 0 1 0 1 1 0 0 3 0 0 0 1 0 1 0 0 2 0 3 0 1 0 1 0 2 1 0 0 0 0 0 0 1 1 1 2 1 2 0 3 0 2 1 2 0 0 0 0 0 0 0 0 0 0 2 1 0 1 1 1 3 0 1 3 1 1 2 0 3 0 1 1 3 0 1 0 1 0 2 1 0 0 0 1 0 1 0 0 0 2 2 3 0 1 0 1 0 0 0 0 0 1 2 1 0 0 0 1 0 0 0 1 0 1 0 0 0 0 0 0 0 0 0 0 1 1 0 0 1 0 0 1 3 0 1 0 1 3 0 0 0 0 0 0 0 1 2 1 0 1 0 0 0 0 0 0 0 0 0 0 1 0 3 0 0 2 1 0 0 0 1 0 0 0 0 0 0 0 0 0 0 1 0 1 0 0 3 0 0 0 0 0 0 0 1 0 1 1 3 0 0 0 1 0 1 1 3 2 0 1 0 1 0 0 1 0 1 0 0 0 1 0 0 1 0 0 0 1 1 1 0 1 0 1 0 0 1 0 1 0 0 1 3 0 1 0 1 1 0 2 1 0 0 0 1 0 0 0 0 3 0 0 1 2 1 0 1 0 1 0 0 0 0 0 0 0 2 1 2 1 0 0 0 2 0 1 0 1 1 0 0 0 0 1 0 0 0 1 0 1 1 1 2 1 2 0 3 0 2 1 0 1 1 1 1 0 1 0 0 0 0 0 0 0 0 0 0 0 0 0 1 0 1 0 0 1 0 1 0 1 1 1 0 0 1 0 1 0 2 1 0 1 0 0 3 0 1 0 0 3 0 1 0 0 0 1 3 1 0 1 0 1 0 0 1 0 1 1 0 2 1 0 1 0 0 3 0 1 0 1 1 0 0 1 1 3 2 0 1 0 0 0 0 0 1 0 1 1 0 1 3 0 0 0 1 3 2 1 0 1 0 0 0 0 0 0 1 1 0 0 1 0 0 1 2 1 0 0 0 1 0 1 1 2 0 0 0 1 0 0 0 0 0 0 0 1 0 1 3 0 1 1 1 0 0 0 1 2 3 0 3 0 0 2 1 0 3 0 1 2 0 1 1 1 1 1 0 1 3 0 1 0 2 1 0 1 3 1 1 2 3 0 1 0 1 0 2 1 0 1 0 0 3 0 3 3 3 3 2 3 1 2 1 3 0 1 0 1 0 1 0 1 1 2 1 0
<br>Final:<br>
4 32 2 8<br>
256 16 128 2<br>
4 2 8 2048<br>
16 128 16 4<br>

On the other hand, if the desired final map cannot be found (such as the last case of the above input file), then you should print -1 for the action and the final map:
<br>
Action:<br>
-1<br>
Final:<br>
-1 -1 -1 -1<br>
-1 -1 -1 -1<br>
-1 -1 -1 -1<br>
-1 -1 -1 -1<br>

<br>
An example output file of the above input file will be provided by TA soon.

<a name=requirement></a>
<h4>Requirements</h4>
<ul>
<li>Limits:
	<ul>
	<li>Max time: 1 minute (total time limit for N=10000).
	<li>Max memory: 256 MB.
	<li>Max submissions: 20 times each week.
	</ul>
<li>You can simply use DFS (exhaustive search) to finish this homework. If you are interested in strategies to speed up the search, here are <a href="http://stackoverflow.com/questions/22342854/what-is-the-optimal-algorithm-for-the-game-2048">some clues</a>.
<li>Note that each map of the game has 16 elements of values ranging from $2^1=2$ to $2^{11}=2048$. As a result, we can use a 64-bit unsigned integer (the data type of "unsigned long long") to represent a map, and each element is characterized by a 4-bit unsigned integer (with values ranging from 0 to 15) to represent its exponent.
<li>How to convert a map to a number in "unsigned long long" (and vice versa):

<img scr="https://cdn-images-1.medium.com/max/1600/1*9UhGjN81QmcSvhEu17PvNA.jpeg">
So the last number can be represented as an integer in "unsigned long long" format (64 bits). Note that you can shift A[m,n]A[m,n] to the left by 4(4m+n)4(4m+n) and do a summation to get the integer in "unsigned long long" format.

<li>TA will provide a function nextMap() to generate the next map based on the current map and the given action. To use the function, please add the following function prototype in your main program:
<center>
unsigned long long nextMap(unsigned long long map, int action);
</center>
where <i>map</i> is the current map, and <i>action</i>=0, 1, 2, 3 corresponding to the action of east, south, west, north, respectively. The function is available as a static library <a href="https://github.com/plsmaop/DSA/raw/master/hw03/lib.a">lib.a</a>. It is quite easy to use the library by the following command:
<p>
g++ -std=c++11 -O2 myProgram.cpp lib.a
</p>
<li>Program usage: Your program should take standard input and generate standard output:
<p>
	myProgram < input.txt > output.txt
	</p>
</ul>


<a name=dataset></a>
<h4>Datasets</h4>
<ol type=a>
<li>Open test sets
	<ul>
	<li>N=10000: <a href="https://github.com/plsmaop/DSA/raw/master/hw03/input10000.txt">input10000.txt</a>, <a href="https://github.com/plsmaop/DSA/raw/master/hw03/output10000.txt">output10000.txt</a>
	</ul>
</ol>

</ol>


</font>
</body>
</html>
