const accountId = 708
let accountEmail ="moon@light.com"
let accountState; //semicolan in not mendatory ";"
var accountPassword ="passfail"
accountCity = "Pokhara"     //not recommended method to declear variable

// accountId = 2         -->>We are not allowed to do so, since accountID is const\
console.log(accountId)  


// To print all variable
console.table([accountEmail,accountState,accountPassword,accountCity,])

// Make change in variable
accountEmail = "face@gmail.com"
accountPassword = "failpass"
accountCity ="Janakpur"


/*  
prefer not to use var
because of issue in block scope and functional scope
*/