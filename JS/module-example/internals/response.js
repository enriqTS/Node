function decrypt(data) {
    return 'decrypt data';
}

function read(){
    return decrypt('data');
}

module.exports = { //Melhor jeito de fazer isso, mas tem as outras opções.
    read,
}