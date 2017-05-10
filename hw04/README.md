

<body>
<!font face="¼Ð·¢Åé">

<center>
<h2>DSA Homework 4</h2>
<h3>Roger Jang</h3>
</center>


<h3 align=center><font color=green>News headline generator (Ranking via heaps)</font></h3>




<a name=problemDefinition></a>
<h4>Problem definition</h4>
<p>In this assignment, you need to implement a news management system that can store a lot of news items, and each item is associated with a score of popularity. In particular, your system should support the following operations:
<ul>
<li>Insert: Insert a news item, and all the existing news items have to depreciate by deducting a given number from their original scores.
<li>Update: For a given set of news ID, we can increase their scores by a given number.
<li>Query: output the highest-score news ID, and its score.
</ul>

<a name=suggestedApproach></a>
<h4>>Suggested approach</h4>
<p>Vector-based heaps.

<a name=inputOutputFormat></a>
<h4>Input/output formats</h4>
<ul>
<li>Input format
	<ul>
	<li>The first line contains two integer, $n$ (the number of operations) and $k$ (the number to be deducted for the existing news items when a new item is added).
	<li>For each of the following $n$ lines, the first integer is $m_i$ which indicates the mode of operation to be executed.
		<ul>
		<li>If $m_i=1$ (insert), it will be followed by $d_i$ (news ID) and $s_i$ (news score), with $0 \leq d_i \leq 10^6$, and $0 \leq s_i \leq 10^6$.
		<li>If $m_i=2$ (update), it will be followed by $v_i$ (the number to be added to scores of the following news ID), $c_i$ (number of news items to be updated), and list of $c_i$ news IDs for update. Note that $0 \leq v_i \leq 10^6$ and $1 \leq c_i \leq 5$. 
		<li>If $m_i=3$ (query), output the news ID with the highest score. (If there is a tie, output the news ID that was inserted most recently.)
		</ul>
	</ul>
	Here is an example input file:<br>
	20 80025<br>
1 15 356051<br>
1 2 392134<br>
1 0 407336<br>
1 7 517303<br>
1 3 631251<br>
2 337391 5 15 15 0 0 0<br>
3<br>
2 471959 2 3 2<br>
2 15587 5 15 2 7 0 15<br>
1 17 139590<br>
2 858380 3 3 17 7<br>
3<br>
1 19 309860<br>
2 102611 4 7 7 17 19<br>
3<br>
1 14 704404<br>
1 10 213329<br>
2 558447 1 0<br>
1 18 609195<br>
3<br>

<li>Output format
	<ul>
	<li>For each query, output a line, as shown in the example output file.
	</ul>
	Here is an example output file:<br>
id: 0, value: 1259459<br>
id: 3, value: 1881565<br>
id: 3, value: 1801540<br>
id: 3, value: 1561465<br>

</ul>

<a name=requirement></a>
<h4>Requirements</h4>
<ul>
<li>Limits:
	<ul>
	<li>Max time: 2 sec (for n=$10^6$).
	<li>Max memory: 256 MB.
	<li>Max submissions: 20 times each week.
	</ul>
<li>Program usage: Your program should take standard input and generate standard output:
	<p>
	myProgram < input.txt > output.txt
	</p>
</ul>


<a name=dataset></a>
<h4>Datasets</h4>
<ol>
<li>Open test sets
	<ul>
	<li><a href="https://github.com/plsmaop/DSA/raw/master/hw04/open03.txt">open03.txt</a>
	<li><a href="https://github.com/plsmaop/DSA/raw/master/hw04/open03_out.txt">open03_out.txt</a>
	<li><a href="https://github.com/plsmaop/DSA/raw/master/hw04/open04.txt">open04.txt</a>
	<li><a href="https://github.com/plsmaop/DSA/raw/master/hw04/open04_out.txt">open04_out.txt</a>
	</ul>
</ol>



