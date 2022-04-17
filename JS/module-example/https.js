const { send, read } = require('./internals');
// const request = require('./request');
// const read = require('./response');

function req(url, data){
    send(url, data);
    return read();
}

const responseData = req('https://google.com');
console.log(responseData);