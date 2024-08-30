<h1>Sorting numbers in two stacks with predetermined rules in c.</h1>
<p>We have A and B stacks. you can only the top digit of stacks a to b or b to a.</p>
<p>In the end you must have a sorted a stack. You must sort 500 numbers under 5500 moves and 100 numbers under 700 moves</p>
<p>You can use this rules to move inside of stacks:</p>
<ul>
    <li>"ra/rb" rules: pushes the first element of the stack to bottom. The second element is first after u use it</li>
    <li>"rra/rrb" rules: pushes the last element of the stack to top. The last element is first after u use it</li>
    <li>"sa/sb" rules: swaps first and second element of stack</li>
    <li>"rr" rule: does ra and rb same time. it counts 1 move in rules</li>
    <li>"rrr" rule: does rra and rrb same time. it counts 1 move in rules</li>
    <li>ss" rule: does sa and sb same time. it counts 1 move in rules</li>
</ul>