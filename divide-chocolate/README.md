<h2>1817. Divide Chocolate</h2><h3>Hard</h3><hr><div><p>You have one chocolate bar that consists of some chunks. Each chunk has its own sweetness given by the array sweetness.</p>

<p>You're going to share this chocolate with <code>K</code> friends, so you need to cut <code>K</code> times to get <code>K + 1</code> pieces, each of which is made up of a series of small pieces.</p>

<p>Being generous, you will eat the piece with the minimum total sweetness and give the other pieces to your friends.

<p>Find the maximum total sweetness of the piece you can get by cutting the chocolate bar optimally.</p>
  
<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>
<pre><strong>Input:</strong> nums = [1,2,3,4,5,6,7,8,9], K = 5
<strong>Output:</strong> 6
<strong>Explanation:</strong> You can divide the chocolate to [1,2,3], [4,5], [6], [7], [8], [9]
</pre><p><strong>Example 2:</strong></p>
<pre><strong>Input:</strong> nums = [5,6,7,8,9,1,2,3,4], K = 8
<strong>Output:</strong> 1
<strong>Explanation:</strong> There is only one way to cut the bar into 9 pieces.
</pre><p><strong>Example 3:</strong></p>
<pre><strong>Input:</strong> nums = [1,2,2,1,2,2,1,2,2], K = 2
<strong>Output:</strong> 5
<strong>Explanation:</strong> You can divide the chocolate to [1,2,2], [1,2,2], [1,2,2]
</pre>
<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>0 &lt;= K &lt; sweetness.length &lt;= 10<sup>4</sup></code></li>
	<li><code>1 &lt;= sweetness[i] &lt;= 10<sup>5</sup></code></li>
</ul>
</div>
