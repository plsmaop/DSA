<body>

<h3 align=center><font color=green>N-gram Search (Information Retrieval)</font></h3>


<a name=problemDefinition></a>
<h4>Problem definition</h4>

<p>Google's <a target=_blank href="http://googleresearch.blogspot.tw/2006/08/all-our-n-gram-are-belong-to-you.html">Web 1T</a> dataset is a big collection of n-grams (with n=2, 3, 4, and 5) of English that can be used for various applications, including machine translation, speech recognition, English usage correction, etc. In this assignment, we need to implement an efficient information retrieval method for querying a slim version of the Web 1T dataset.

<p>Given a query of n-gram, you program should return its frequency based on the slim Web 1T. The given n-gram query can be a simple query such as "listen to music" or "in a position to". Additionally, it can contains wildcards and special characters to make the query more flexible, as explain next.
<ul>
<li>"-" (underscore) can be used to represent a word (token).
	<br>For instance, "listen _ music"
<li>"*" (asterisk) can be used to represent zero or more words
	<br>For instance, "a * book"
<li>"?" can be used as a prefix to denote a word as optional
	<br>For instance, "discuss ?about the issue"
<li>"/" can be used to denote all alternatives
	<br>For instance, "in/at/on the afternoon"
</ul>
<!--
For simplicity, we assume each query can only contain a single type of these special characters, perhaps multiple times. 
-->
To test these special characters, please try <a target=_blank href="linggle.com">Linggle</a>.

<a name=suggestedApproach></a>
<h4>Suggested approach</h4>
The basic approach is based on inverted index. In other words, for a give word, we need to be able to find which n-gram it appears. More info can be found in the first three sections of <a href="http://nlp.stanford.edu/IR-book/html/htmledition/boolean-retrieval-1.html">Boolean retrieval</a>:
<ul>
<li><a href="http://nlp.stanford.edu/IR-book/html/htmledition/an-example-information-retrieval-problem-1.html">An example information retrieval problem</a>
<li><a href="http://nlp.stanford.edu/IR-book/html/htmledition/a-first-take-at-building-an-inverted-index-1.html">A first take at building an inverted index</a>
<li><a href="http://nlp.stanford.edu/IR-book/html/htmledition/processing-boolean-queries-1.html">Processing Boolean queries</a>
</ul>
<p>Tutorials by Stanford NLP-Professor Dan Jurafsky & Chris Manning
<ul>
<li><a href="https://www.youtube.com/watch?v=pevQ2T9Gm0w">Inverted index</a>
<li><a href="https://www.youtube.com/watch?v=6Md_ZGW-wbk">Merge postings</a>
</ul>

<p>To be more precise, here is a typical approach to the problem:
<ul>
<li>Preprocess
	<ol>
	<li>Extract all words from the n-gram dataset
	<li>Create a dictionary of all sorted unique words
	<li>Generate a posting for each word in the dictionary
	</ol>
<li>Online processing
	<ol>
	<li>Expand the query until it contains only words or "_".
	<li>Extract words from the query
	<li>Retrieve each word (by binary search or the likes) and its posting from one of the n-gram sets 
	<li>Combine postings to have the candidate output set
	<li>Generate final output by considering ordering.
	<li>Sort and print the output ordered by frequency
	</ol>
</ul>
For query expansion, you need to follow the rules shown next (which may not be exactly the same as those used by Linggle):
<ol>
<li>First, expand "?" (which, if exist, always applear as the first character in a token). For instance, "abc ?x/y/z _ ?*/p" can be expanded into the following 4 queries:
	<ul>
	<li>abc _
	<li>abc _ */p
	<li>abc x/y/z _
	<li>abc x/y/z _ */p
	</ul>
<li>Second, expand "/". For instance, "abc x/y/z _ */p" can be expanded into the following 6 queries:
	<ul>
	<li>abc x _ *
	<li>abc x _ p
	<li>abc y _ *
	<li>abc y _ p
	<li>abc z _ *
	<li>abc z _ p
	</ul>
<li>Last, expand "*" into emptiness or combinations of "_". For instance, "give * a *" can be expaneded into the following 10 queries:
	<ul>
	<li>give a
	<li>give a _
	<li>give a _ _
	<li>give a _ _ _
	<li>give _ a
	<li>give _ a _
	<li>give _ a _ _
	<li>give _ _ a
	<li>give _ _ a _
	<li>give _ _ _ a
	</ul>
</ol>
Note that it will be easier to write a recursive function for each of the above expansions. 

<a name=inputOutputFormat></a>
<h4>Input/output formats</h4>
<p>An typical example of input file is as follows, where each line is a query:

regarding our site to
occupation does
resolution with all
eliminated _ _ the
resulted from negligent
understand that you _ _
alprazolam international
free/on cartoon sex _
and _ states
storing large _ of/for/with data</p>


<p>For each query, you only need to generate at most top-5 output with ascending order of frequency. If there is tie, list them according to alphabetical order of the n-grams. The output file corresponding to the previous input file is shown next:</p>
<span>
query: regarding our site to
output: 1
regarding our site to	1103
query: occupation does
output: 1
occupation does	4704
query: resolution with all
output: 1
resolution with all	6938
query: eliminated _ _ the
output: 5
eliminated most of the	6744
eliminated many of the	4848
eliminated some of the	4467
eliminated all of the	4131
eliminated much of the	3933
query: resulted from negligent
output: 1
resulted from negligent	3434
query: understand that you _ _
output: 5
understand that you do not	11830
understand that you can not	9507
understand that you are not	6594
understand that you are using	5366
understand that you want to	5175
query: alprazolam international
output: 1
alprazolam international	1414
query: free/on cartoon sex _
output: 5
free cartoon sex video	10298
free cartoon sex free	7323
free cartoon sex pics	4177
free cartoon sex movie	3575
free cartoon sex film	2412
query: and _ states
output: 5
and other states	139463
and the states	105148
and surrounding states	25879
and all states	17070
and some states	16149
query: storing large _ of/for/with data
output: 1
storing large amounts of data	2578


Each output entry and its frequency are separated by a tab.</span>

<a name=requirementSuggestion></a>
<h4>Requirements</h4>
<ul>
<li>Limits:
	<ul>	
	<li>Max time: 180 second.
	<li>Max memory: 7 GB.
	<li>Max submissions: 20 times each week, starting at "20170320 23:59:59" and ending at "20170403 23:59:59".
	</ul>
<li>Program usage: Your program should take an input argument to indicate the directory which holds the n-gram files. The default file names are shown in the download links listed below. And the input file (which holds the queries) can be redirect to the program. An example follows. 
<p>
	myProgram /tmp2/dsa2017_hw02/ < input00.txt > outptut00.txt
	</p>


<a name=dataset></a>
<h4>Datasets</h4>
<ol type=a>
<li>The original Google Web 1T dataset is too big to process for machines with limited memory. Hence we shall use a subset for this project, as shown next. These files are already available under /tmp2/dsa2017_hw02/ of linux1 to linux13.
	<ul>
	<li><a href="../../../project/2016/2gm.small.txt">2-grams (bigrams)</a>
	<li><a href="../../../project/2016/3gm.small.txt">3-grams (trigrams)</a>
	<li><a href="../../../project/2016/4gm.small.txt">4-grams (fourgrams)</a>
	<li><a href="../../../project/2016/5gm.small.txt">5-grams (fivegrams)</a>
	</ul>
<li>Open test sets
	<ul>
	<li><a href="testCase/input0010.txt">input0010.txt</a>, <a href="testCase/output0010.txt">output0010.txt</a>
	<li><a href="testCase/input0100.txt">input0100.txt</a>, <a href="testCase/output0100.txt">output0100.txt</a>
	<li><a href="testCase/input1000.txt">input1000.txt</a>, <a href="testCase/output1000.txt">output1000.txt</a>
	</ul>
<li>Hidden test sets
	<ul>
	<li><a href="testCase/input1000-hidden.txt">input1000-hidden.txt</a>, <a href="testCase/output1000-hidden.txt">output1000-hidden.txt</a>
	</ul>



</body>
</html>
