function reverseWords(s: string): string {
    var res: string = "";
    var x: string[] = s.split(" ");
    x = x.reverse();
    for (var i of x) {
        if (i == '') continue;
        res += i;
        res += " ";
    }
    //console.log('arr is: ' + x);
    return res.trim();
};