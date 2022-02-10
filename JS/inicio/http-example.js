const { request } = require('https');
const { get } = require('https');

// const request = request('https://www.google.com', (response) => {
get('https://www.google.com', (response) => {
    response.on('data', (chunk) => {
        console.log(`Data chunk: ${chunk}`);
    });
    response.on('end', () => {
        console.log('No more data');
    });
});

//request.end();