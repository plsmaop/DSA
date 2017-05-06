<html>
<head>
	<title>DSA Homework 1</title>
	<meta HTTP-EQUIV="Content-Type" CONTENT="text/html; charset=big5">
	<style>
		td {font-family: "夹发砰", "helvetica,arial", "Tahoma"}
		A:link {text-decoration: none}
		A:hover {text-decoration: underline}
	</style>
</head>

<body background="/jang/graphics/background/yellow.gif">
<!font face="夹发砰">

<center>
<h2><a href="/jang/courses/dsa">DSA</a> Homework 1</h2>
<h3><a href="/jang">Roger Jang</a></h3>
</center>

<hr>
<strong>Due date: <font color=red>20170313 23:59:59</font></strong>
<hr>

<h3 align=center><font color=green>Range Maximum Query</font></h3>

<h4><img src="/jang/graphics/dots/redball.gif">Problem definition</h4>
Given an array of $n$ integer $\{a_1, a_1, ..., a_n\}$ and a range of $[l, u]$, the range maximum query returns the maximum of $\{a_l, a_{l+1}, ..., a_u\}$. Usually the array is static (elements are fixed), and we need to perform the query $m$ times with different ranges.

<p>There are several approaches to range maximum query, with different complexities in speed and storage, and preprocessing, as explained next. Your mission is to pick one of them for your implementation to meet the requirement of this assignment. (We will briefly review these methods in class.)

<ul>
<li>straightforward search: Run a loop from $l$ to $u$ and find the maximum
in the given range.
	<ul>
	<li>Query: $O(n)$
	<li>Memory: $O(1)$
	<li>Preprocess: $O(1)$
	</ul>
<li>Naive method: Create a matrix B where B[i,j] stores the maximum within $\{a_i, a_{i+1}, ..., a_j\}$.
	<ul>
	<li>Query: $O(1)$
	<li>Memory: $O(n^2)$
	<li>Preprocess: $O(n^2)$
	</ul>
<li>Square root decomposition: Split the array into $\sqrt{n}$ subarrays of size $\sqrt{n}$ and precompute the maximum of each subarray.
	<ul>
		<script>showImage("image/squareRoot.png");</script>
	<li>Query: $O(\sqrt{n})$
	<li>Memory: $O(\sqrt{n})$
	<li>Preprocess: $O(n)$
	</ul>
<li>Iterative doubling (or sparse table algorithm): Precompute the maximum of each subarray of length $2^k$. Note that the range $[l,u]$ can be expressed as $[l,l+2^k-1]\cup[u-2^k+1, u]$ for a certain value of $k$.
	<script>showImage("image/doubling.png");</script>
	<ul>
	<li>Query: $O(1)$
	<li>Memory: $O(n\log n)$
	<li>Preprocess: $O(n\log n)$
	</ul>
<li>Segment tree: Precompute the maximum of the entire array. Split the array into two subarrays and recurse.
	<script>showImage("image/tree.png");</script>
	<ul>
	<li>Query: $O(\log n)$
	<li>Memory: $O(n)$
	<li>Preprocess: $O(n)$
	</ul>
</ul>

References:
<ul>
<li><a href="https://en.wikipedia.org/wiki/Range_minimum_query">Wikipedia</a>: 4 methods
<li><a href="http://www.geeksforgeeks.org/range-minimum-query-for-static-array/">Range Minimum Query (Square Root Decomposition and Sparse Table)</a>: Simple solution, square root decomposition, sparse table algorithm
<li><a href="http://www.geeksforgeeks.org/segment-tree-set-1-range-minimum-query/">Range Minimum Query</a>: Segment trees
<li><a href="http://www.csie.ntnu.edu.tw/~u91029/Sequence.html">Sequence 戈挡篶: Array / List</a>: sparse table algorithm
</ul>

<h4><img src="/jang/graphics/dots/redball.gif">I/O formats</h4>
<ul>
<li>Input format
	<ul>
	<li>The first line of the input contains two integers, $n$ (length of the array) and $m$ (number of queries), with $1\leq n, m \leq 100000$.
	<li>The second line contains $n$ integers, $a_1, a_2, ..., a_{n}$, with $0 \leq a_i \leq 10^9$.
	<li>Each of the following $m$ lines contains two integers, $l_i$ and $u_i$, which are the lower and upper indices for the $i$th query.
<!--
	<li>For 60% of the input, $1 \leq n, m \leq 5000$.
-->
	</ul>
<li>Output format
	<ul>
	<li>Print one integer for each query.
	</ul>
<li>Example
	<p>Input:
<xmp>
5 3
10 30 50 20 40
1 5
1 2
4 5

</xmp>
	<p>Output:
<xmp>
50
30
40
</xmp>
</ul>

<h4><img src="/jang/graphics/dots/redball.gif">Test cases</h4>
<ol>
<li>n=5. m=3 ==> <a href="test/input_5_3.txt">input</a>, <a href="test/output_5_3.txt">output</a>
<li>n=100000. m=100000 ==> <a href="test/input_100000_100000.txt">input</a>, <a href="test/output_100000_100000.txt">output</a>
</ol>

<h4><img src="/jang/graphics/dots/redball.gif">Requirements</h4>
<ul>
<li>Limits
	<ul>
	<li>Time limit: 1 second.
	<li>Memory limit: 256MB. (This may preclude the use of the naive method which requires $O(n^2)$ memory.)
	</ul>
<li>You need to use max() in STL. (So you need to put "#include &lt;algorithm&gt;" in your code.)
</ul>



<h4><img src="/jang/graphics/dots/redball.gif">Side notes</h4>
<ul>
<li>Be aware that our description of indexing here is 1-based, while the indexing of C/C++ is 0-based.
<li>In practice, range maximum query returns the position instead of the element.
<li>As usual...
	<ol type=a>
	<li>Your program should take the input from the standard input and send the output to the standard output. That is, you should be able to redirect the input/output files like this:
	<center>
	myProgram < input.txt > output.txt
	</center>
	<li><font color=red>You need to write the program from scratch. You cannot use any open-source or readily available solvers.</font>
	</ol>
</ul>



</font>
</body>
</html>
