const request = require('./request');
const read = require('./response');

function req(url, data){
    request.send(url, data);
    return read();
}

const responseData = req('https://google.com');
console.log(responseData);