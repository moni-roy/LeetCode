/**
 * @param {number} n
 * @return {number[]}
 */
 var countBits = function(n) {
    var result = [];
    result[0] = 0;
    for (var i = 1; i <= n; i++) {
        result[i] = result[i >> 1] + (i & 1); 
    }
    return result;
};