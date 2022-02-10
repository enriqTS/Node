const EventEmitter = require('events');
const celebrity = new EventEmitter();

celebrity.on('race', (result) => {
    if(result === 'win'){
        console.log('Congratulations.');
    } 
});

celebrity.on('race', (result) => {
    if(result === 'lost'){
        console.log('Good luck next time.');
    }   
});

process.on('exit', (code) => {console.log('Process exit event with code: ', code)});

celebrity.emit('race', 'win');
celebrity.emit('race', 'lost');

