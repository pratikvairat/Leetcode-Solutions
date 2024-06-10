/**
 * @param {...(null|boolean|number|string|Array|Object)} args
 * @return {number}
 */
var argumentsLength = function(...args) {
    var cn=0;
    for(let i in args){
        cn++;
    }
    return cn;
};

/**
 * argumentsLength(1, 2, 3); // 3
 */