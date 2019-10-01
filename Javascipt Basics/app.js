// $$ hello world $$

function hello()
{
    console.log('hello world');
}
hello();

// $$ hoisting of variable $$

var a = 25;
if(true)
{
    var a = 35;
    console.log(a);
}
console.log(a); 

let a = 25
if(true)
{
    let a = 35;
    console.log(a);
}
console.log(a);

// 'let' has local scope and 'var' has global scope

//  $$ hoisting $$

abc();

function abc()
{
    console.log('abc');
}