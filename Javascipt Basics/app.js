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

// $$ const $$

const obj = {d:25};
obj.d = 111;
console.log(obj.d);

// $$ functions $$

function abc(a, b, c)
{
    console.log(a + " ", b + " ", c + " ");
}
abc(10, 20, 30);

function abc(a=10, b, c)
{
    console.log(a + " ", b + " ", c + " ");
}
abc(10, 20);

function abc(...a)
{
    console.log(a);
}
abc(10, 20, 30);

// $$ arrow functions $$

var hello = () => {
    console.log('hello world');
}
hello();

var hello = (a = 20, b = 30) => {
    console.log(a+b);
}
hello();

var hello = a => {
    console.log();
}
hello(20);

// $$ .map() $$ 

var officers = [
    { id: 20, name: "Captain Piett" },
    { id: 24, name: "General Veers" },
    { id: 56, name: "Admiral Ozzel" },
    { id: 88, name: "Commander Jerjerrod" }
  ];
  
const officersIds = officers.map(officer => officer.id);
console.log(officersIds);