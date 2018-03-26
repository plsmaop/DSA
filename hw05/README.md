<html><head><script>
function editfile() {
        var keycode = event.keyCode;
        if (keycode==120) {
                document.location="editfile.asp?FileName=/jang/courses/dsa/homework/2017/hw05/index.asp"
        }
}
</script>
<script>document.onkeydown=editfile;</script>

<script src="DSA%20Homework%205_files/utility4webClient.js"></script>

<!-- For using MathJax?? -->
<script type="text/x-mathjax-config">MathJax.Hub.Config({tex2jax: {inlineMath: [['$','$'], ['\\(','\\)']]}});</script>
<script type="text/javascript" src="DSA%20Homework%205_files/MathJax.js"></script>



	<title>DSA Homework 5</title>
	<meta http-equiv="Content-Type" content="text/html; charset=Big5">
	<style>
		td {font-family: "¼Ð·¢Åé", "helvetica,arial", "Tahoma"}
		A:link {text-decoration: none}
		A:hover {text-decoration: underline}
	</style>
</head>

<body background="DSA%20Homework%205_files/yellow.gif">
<!--font face="¼Ð·¢Åé"-->

<center>
<h2><a href="https://mirlab.org/jang/courses/dsa">DSA</a> Homework 5</h2>
<h3><a href="https://mirlab.org/jang">Roger Jang</a></h3>
</center>

<hr>
<strong>Due date: <font color="red">20170605 23:59:59</font></strong>
<hr>

<h3 align="center"><font color="green">Dice sum game</font></h3>

<!--
<center><font color=red>Details not yet finalized!</font></center>
-->

Outlines
<ul>
<li><a href="https://mirlab.org/jang/courses/dsa/homework/2017/hw05/index.asp#problemDefinition">Problem definition</a>
</li><li><a href="https://mirlab.org/jang/courses/dsa/homework/2017/hw05/index.asp#suggestedApproach">Suggested approach</a>
</li><li><a href="https://mirlab.org/jang/courses/dsa/homework/2017/hw05/index.asp#inputOutputFormat">Input/output formats</a>
</li><li><a href="https://mirlab.org/jang/courses/dsa/homework/2017/hw05/index.asp#requirement">Requirements</a>
</li><li><a href="https://mirlab.org/jang/courses/dsa/homework/2017/hw05/index.asp#dataset">Datasets</a>
</li></ul>

<a name="problemDefinition"></a>
<h4><img src="DSA%20Homework%205_files/redball.gif">Problem definition</h4>
	<ul>
	<p>See the slides of <a href="https://mirlab.org/jang/books/dcpr/slide/dp-game.ppt">DP for optimum strategies in games</a>
	</p></ul>

<a name="suggestedApproach"></a>
<h4><img src="DSA%20Homework%205_files/redball.gif">Suggested approach</h4>
	<ul>
	<p>Dynamic programming.
	</p></ul>

<a name="inputOutputFormat"></a>
<h4><img src="DSA%20Homework%205_files/redball.gif">Input/output formats</h4>
<blockquote>
In this assignment, you need to design a function myStrategy() to 
determine where to place the dice value. Together with the main function
 (which is given by TA), you should be able compile and run the program 
to get the average score of 1,000,000 runs of the game.
</blockquote>
<ul>
<li>Main program: <a href="https://mirlab.org/jang/courses/dsa/homework/2017/hw05/gameEvalMain.cpp">gameEvalMain.cpp</a>
</li><li>Your strategy: <a href="https://mirlab.org/jang/courses/dsa/homework/2017/hw05/myStrategy.cpp">myStrategy.cpp</a>
</li><li>Header file: <a href="https://mirlab.org/jang/courses/dsa/homework/2017/hw05/game.h">game.h</a>
</li></ul>
<blockquote>
Once you have the above 3 files, you can compile the program:
<center>
g++ gameEvalMain.cpp myStrategy.cpp
</center>
Then you can run the program directly. My result is like this:
</blockquote>
<ul>
<li>When strategy==1, the average score is around 57.
</li><li>When strategy==2, the average score is about 67.
</li></ul>
<blockquote>
Your mission is to modify myStrategy.cpp by adding DP to strategy 3. If 
implemented correctly, the program can generate an average score of 118 
or so. The theoretical max score achieved by DP is 118.62.
</blockquote>

<a name="requirement"></a>
<h4><img src="DSA%20Homework%205_files/redball.gif">Requirements</h4>
<ul>
<li>Limits:
	<ul>
	<li>Time: 3 sec
	</li><li>Memory: 32 MB
	</li></ul>
</li><li>You get the full score if the average score is higher than 117 
after 1,000,000 rounds of test. (It doesn't matter if you are using DP 
or not.)
</li><li>Do NOT print anything in myStrategy(), otherwise you'll get WA due to messed output.
<!--
<li>Program usage: Your program should take standard input and generate standard output:
<center>
	myProgram < input.txt > output.txt
</center>
-->
</li></ul>


<a name="dataset"></a>
<h4><img src="DSA%20Homework%205_files/redball.gif">Datasets</h4>
<ol type="a">
None.
</ol>



<hr>

<script language="JavaScript">
document.write("Last updated on " + document.lastModified + ".")
</script>Last updated on 03/26/2018 15:19:55.

<a href="https://mirlab.org/jang/sandbox/asp/lib/editfile.asp?FileName=/jang/courses/dsa/homework/2017/hw05/index.asp"><img src="DSA%20Homework%205_files/invisible.gif" border="0" align="right"></a>


</body></html>
