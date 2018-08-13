var usersList = document.getElementById('usersList');
var nameInput = document.getElementById('nameInput');
var ageInput = document.getElementById('ageInput');
var addButton = document.getElementById('addButton');

addButton.addEventListener('click', () => {
    create(nameInput.value, ageInput.value);
});

function create(name, age) {
    var data = {
        name: name,
        age: age
    };

    return firebase.database().ref().child('users').push(data);
}

/*
    <tr class="table-primary">
        <td>teste1</td>
        <td>teste2</td>
    </tr>

    usersList.innerHTML = '';

    var tr = document.createElement('tr');
    tr.classList.add('table-primary');

    var tdName = document.createElement('td').appendChild(document.createTextNode('NOME1'));;

    var tdAge = document.createElement('td').appendChild(document.createTextNode('IDADE1'));;

    tr.appendChild(tdName);
    tr.appendChild(tdAge);

    usersList.appendChild(tr);
*/

firebase.database().ref('users').on('value', (snapshot) => {
    usersList.innerHTML = '';
    var i = 1;
    // Item vem do snapshot
    snapshot.forEach( (item) => {
        var li = document.createElement('li');
        li.classList.add('list-group-item');
        li.appendChild(document.createTextNode(i + ' | Nome: ' +  item.val().name + '  |  Idade: ' + item.val().age));
        usersList.appendChild(li);
        i++;
        console.log(li);

    });
})