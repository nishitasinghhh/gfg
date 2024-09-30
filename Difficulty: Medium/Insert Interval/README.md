<h2><a href="https://www.geeksforgeeks.org/problems/insert-interval-1666733333/1">Insert Interval</a></h2><h3>Difficulty Level : Difficulty: Medium</h3><hr><div class="problems_problem_content__Xm_eO"><p><span style="font-size: 18px;">Geek has&nbsp;an array of <strong>n </strong>non-overlapping intervals&nbsp;<strong><code>intervals</code>&nbsp;</strong>where&nbsp;<code>intervals[i] = [start<sub>i</sub>, end<sub>i</sub>]</code>&nbsp;represent the start and the end of the&nbsp;<code>i<sup>th</sup></code>&nbsp;event and&nbsp;<strong><code>intervals</code>&nbsp;</strong>is sorted in ascending order by&nbsp;<strong><code>start<sub>i</sub></code></strong>. He wants to add a new interval <strong>newEvent </strong>=&nbsp;<strong><code>[newStart, newEnd]</code>&nbsp;</strong>where newStart and newEnd represent the start and end of this interval.</span></p>
<p><span style="font-size: 18px;">Help Geek to insert&nbsp;<strong>newEvent </strong>into&nbsp;<strong><code>intervals</code>&nbsp;</strong>such that&nbsp;<strong><code>intervals</code>&nbsp;</strong>is still sorted in ascending order by&nbsp;<code>start<sub>i</sub></code>&nbsp;and&nbsp;<strong><code>intervals</code>&nbsp;</strong>still does not have any overlapping intervals (merge overlapping intervals if necessary).</span></p>
<p><span style="font-size: 18px;"><strong>Examples:</strong></span></p>
<pre><span style="font-size: 18px;"><strong>Input: </strong>intervals = [[1,3], [10,15], [20,30]], newEvent = [5,6]
<strong>Output: </strong>[[1,3], [5,6], [10,15], [20,30]]
<strong>Explanation: </strong>The newEvent (5, 6) does not overlap with any of the existing ranges, hence it is added </span>
<span style="font-size: 18px;">to the intervals list maintaining the sorted order of start times.</span>
</pre>
<pre><span style="font-size: 18px;"><strong>Input: </strong>intervals = [[1,2],[3,5],[6,7],[8,10],[12,16]], newEvent = [5,10]
<strong>Output: </strong>[[1,2], [3,10], [12,16]]
<strong>Explanation: </strong>Because the new interval [5,10] overlaps with [3,5],[6,7],[8,10].</span></pre>
<p><span style="font-size: 18px;"><strong>Expected Time Complexity:</strong> O(n)<br><strong>Expected Auxiliary Space:</strong> O(n)</span></p>
<p><span style="font-size: 18px;"><strong>Constraints:</strong><br>1 ≤ n ≤&nbsp; 10<sup>4</sup><br>0 ≤ start[i], end[i]&nbsp;≤ 10<sup>9</sup></span></p></div>