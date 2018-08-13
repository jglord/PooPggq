var usersList = document.getElementById('usersList');
var nameInput = document.getElementById('nameInput');
var ageInput = document.getElementById('ageInput');
var addButton = document.getElementById('addButton');
//var delButton = document.getElementById('delButton');

addButton.addEventListener('click', () => {
    create(nameInput.value, ageInput.value);
});
/*
delButton.addEventListener('click', () => {
    deleteUser(userKey);
});*/

function deleteUser(userKey) {
    return firebase.database().ref().child(`users/${userKey}`).remove();
}


function create(name, age) {
    var uid = firebase.database().ref().child('users').push().key;
    
    var data = {
        name: name,
        age: age,
        userId: uid
    };

    var updates = {};
    updates['/users/' + uid] = data;

    return firebase.database().ref().update(updates);

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

function listUsers() {
    firebase.database().ref('users').on('value', (snapshot) => {
        usersList.innerHTML = '';
        let lista = [];
        // Item vem do snapshot
        
        snapshot.forEach( (item) => {
            const data = item.val();
            const userId = item.key;
            lista.push({userId, ...data});
    
            // lista
            var li = document.createElement('li');
            li.classList.add('list-group-item');
            li.appendChild(document.createTextNode('Nome: ' +  item.val().name + '  |  Idade: ' + item.val().age));
            
            // delete button
            let deleteButton = document.createElement('button');
            deleteButton.appendChild(document.createTextNode('X'));
            deleteButton.setAttribute("type","button");
            deleteButton.classList = "btn btn-danger";
            deleteButton.addEventListener('click', () => {
                if (confirm(`deseja deletar ${item.val().name}`)) {
                    alert(`Pessoa ${item.val().name}`);
                    deleteUser(item.key);
                    listUsers();
                } else {
                    alert('else')
                }
            });
            li.appendChild(deleteButton);

            usersList.appendChild(li);
        });
    });
}
listUsers();