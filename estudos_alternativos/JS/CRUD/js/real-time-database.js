var nameInput = document.getElementById('nameInput');
var ageInput  = document.getElementById('ageInput');
var addButton = document.getElementById('addButton');

addButton.addEventListener('click', function() {
    create(nameInput.value, ageInput.value);
});

function create(name, age) {
    var data = {
        name: name,
        age: age
    };

    console.log(data);

}
