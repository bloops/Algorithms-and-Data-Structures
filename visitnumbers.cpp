void rec(int x = 0){ 
    if(x > ulimit) return;
    // VISIT(x);
    if(x > 0) rec(10*x);
    FOR1(d,9) rec(10*x + d);
}
/*

* rec() VISITs every integer in [0, ulimit]

* invariant: rec(x) will visit all numbers of the form xs (where s is any string)

* the check x > ulimit being in the beginning of the function saves a lot of code repetition

* the code can visit all numbers between 0 and ulimit having property p
  where p is a property such that if n has the property, all prefixes of n will also have the property

*/
