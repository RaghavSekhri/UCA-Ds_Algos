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

// $$ objects $$

let obj = {};
obj.name = 'abc';
obj.age = 20;
console.log(obj);
console.log(obj.name);
console.log(obj.age);
obj.name = 'xyz';
console.log(obj.name);
  
let obj1 = {
    name: 'zues',
    age: 16,
    interests: ['coding', 'reading books', 'running'],
    greet: function(){
      console.log('hi')
  },
    address: {street: 12, sector: 46}
  };
console.log(obj1.greet());
console.log(obj1.interests[0]);
console.log(obj1.address.sector);

// $$ object instance $$

let obj = new person("abc");
let obj1 = new person("xyz");
function person(name)
{
    this.name = name;
    this.greet = function()                           // using this function as a constructor
    {
        return "Hello " + this.name;
    }
}
console.log(obj.name);
console.log(obj1.name);