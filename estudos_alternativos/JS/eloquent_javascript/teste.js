


var number = 123;

console.log(parseInt(number.toString().split('').reverse().join('')));






var array = [
    { name: "Itagores Lira", mother: "Ionara", 
      sexo: "m",
      curso: "Ciência da computação"},
    { name: "João Goulart", mother: "Laurita",
      sexo: "m",
      curso: "Ciência da computação"}
]

function map(array, transform) {
    var mapped = [];
    for(var i = 0; i < array.length; i++) {
        mapped.push(transform(array[i]))
    }
    return mapped;
}

/*var names = filter(array, (person) => {
    return person.name;
});

console.log(map(names, (person) => {
    return person.name;
}));*/


function filter(array, test) {
    var okay = [];
    for(var i = 0; i < array.length; i++) {
        if(test(array[i])){
            okay.push(array[i]);
        }
    }
    return okay;
}
//
//console.log(array.filter((person) => {
//    return person.mother === "Laurita";
//}));




















var numbers = [1, 2, 3, 4, 5], sum = 0;
numbers.forEach(function(number) {
  sum += number;
});
//console.log(sum);

function greaterThan(n) {
    return function(m) { return m > n; };
}

var greaterThan10 = greaterThan(10);
//console.log(greaterThan10(11));
// → true



function isEven(n) {
    if( n == 0 ) {
        console.log("é par.");
    } 
    else if( n == 1 ) {
        console.log("é impar.");
    } 
    else {
        n = isEven( n - 2 );
    }
}
    
function countBs(str) {

    var count  = 0;
    for(var i = 0; i < str.length; i++) {
        if (str.charAt(i) == "b" || str.charAt(i) == "B"){
            count++;
        }
    }
    
    return count;    
}

function countChar(str, char) {

    var count = 0;
    for (var i = 0; i < str.length; i++) {
        if (str.charAt(i) == char) {
            count++;
        }
    }

    return count;
}
