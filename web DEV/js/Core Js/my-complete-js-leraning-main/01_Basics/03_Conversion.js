let score = "33";
let scar = "33abc";

// const {score} = req.body -->

// console.log(typeof score);
// console.log(typeof score);

let valueInNumber = Number(score);
let valueInScar = Number(scar);
// console.log(typeof valueInNumber);
// console.log(typeof valueInScar);
// console.log(valueInScar); // NaN as "33abc" is not a proper number

let nullTest = null;
// let nullConv = Number(nullTest);
// console.log(nullConv);

let undTest = undefined;
let undConv = Number(undTest);
// console.log(undConv);



/*
"33" => 33
"33abc" => NaN // Not A Number
"true" => 1 
"false" => 0 
*/

let isLoggedIn = "";
let booleanIsLoggedIn = Boolean(isLoggedIn)
// console.log(booleanIsLoggedIn);

let Num = 4982378;
let str = String(Num);
console.log(typeof str);