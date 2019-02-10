var fs = require('fs');
var str;
fs.readFile("./sound.list", function(err, data) {
    if (err) {
        console.error(err);
    } else {
        console.log(data.toString());
        str=data.toString();
        var wordArr=str.split('.');
        console.log(str);
        console.log(wordArr[1]);
    }
});
