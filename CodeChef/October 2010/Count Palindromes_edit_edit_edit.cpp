// This does the expanding bit.
function getsize(s, start, end) {
    var count = 0, i, j;
    for (i = start, j = end; i >= 0 && j < s.length; i--, j++) {
        if (s[i] !== s[j]) {
            return count;
        }
        count = j - i + 1; // keeps track of how big the palindrome is
    }
    return count;
}

function getBiggestPalindrome(s) {
    // test for simple cases
    if (s === null || s === '') { return 0; }
    if (s.length === 1) { return 1; }
    var longest = 1;
    for (var i = 0; i < s.length - 1; i++) {
        var c = s[i]; // the current letter
        var l; // length of the palindrome
        if (s[i] === s[i+1]) { // this is a 2 letter palindrome
            l = getsize(s, i, i+1);
        }
        if (i+2 < s.length && s[i] === s[i+2]) { // 3 letter palindrome
            l = getsize(s, i+1, i+1);
        }
        if (l > longest) { longest = l; }
    }
    return longest;
}
