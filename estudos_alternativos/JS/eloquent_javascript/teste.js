
console.log(countChar("kakkerlak","k"));


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
