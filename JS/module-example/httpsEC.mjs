import {send} from './requestEC.mjs';
import {read} from './responseEC.mjs';

function req(url, data){
    send(url, data);
    return read();
}

const responseData = req('https://google.com');
console.log(responseData);