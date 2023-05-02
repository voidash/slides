var _a;
var LocalStorageManager = /** @class */ (function () {
    function LocalStorageManager(storageKey) {
        this.storageKey = storageKey;
    }
    LocalStorageManager.prototype.get = function () {
        var storedList = window.localStorage.getItem(this.storageKey);
        return storedList ? JSON.parse(storedList) : [];
    };
    LocalStorageManager.prototype.set = function (todoList) {
        console.log("setting");
        window.localStorage.setItem(this.storageKey, JSON.stringify(todoList));
    };
    return LocalStorageManager;
}());
var TodoListManager = /** @class */ (function () {
    function TodoListManager(manager) {
        this.todoList = manager.get();
        this.storageManager = manager;
    }
    TodoListManager.prototype.addTodoItem = function (text) {
        var newTodoItem = {
            id: Date.now(),
            text: text,
            completed: false,
        };
        this.todoList.push(newTodoItem);
        this.storageManager.set(this.todoList);
        renderDom(this);
    };
    TodoListManager.prototype.deleteTodoItem = function (id) {
        this.todoList = this.todoList.filter(function (todoItem) { return todoItem.id !== id; });
        this.storageManager.set(this.todoList);
        renderDom(this);
    };
    TodoListManager.prototype.completeTodoItem = function (id) {
        this.todoList = this.todoList.map(function (todoItem) {
            if (todoItem.id === id) {
                todoItem.completed = true;
            }
            return todoItem;
        });
        this.storageManager.set(this.todoList);
        renderDom(this);
    };
    TodoListManager.prototype.getAllTodoItems = function () {
        return this.todoList;
    };
    return TodoListManager;
}());
function renderDom(listManager) {
    var parent = document.querySelector("#todo-cards");
    parent.innerHTML = "";
    var toRender = listManager.getAllTodoItems().map(function (todo) {
        var card = document.createElement("div");
        card.setAttribute("id", "todo-card");
        var description = document.createElement("span");
        description.appendChild(document.createTextNode(todo.text));
        if (todo.completed) {
            description.style.textDecoration = "line-through";
        }
        var deleteButton = document.createElement("button");
        deleteButton.appendChild(document.createTextNode("delete"));
        deleteButton.addEventListener("click", function (_) {
            listManager.deleteTodoItem(todo.id);
        });
        var completeButton = document.createElement("button");
        completeButton.appendChild(document.createTextNode("completed?"));
        completeButton.addEventListener("click", function (_) {
            listManager.completeTodoItem(todo.id);
        });
        card.appendChild(description);
        card.appendChild(deleteButton);
        card.appendChild(completeButton);
        return card;
    });
    toRender.map(function (element) { return parent === null || parent === void 0 ? void 0 : parent.appendChild(element); });
}
var storageManager = new LocalStorageManager("todo-lists");
var todoManager = new TodoListManager(storageManager);
renderDom(todoManager);
var submit = document.querySelector("#add");
(_a = document.querySelector("#add")) === null || _a === void 0 ? void 0 : _a.addEventListener("click", function (_) {
    var input = document.querySelector("#todo-element");
    if ((input === null || input === void 0 ? void 0 : input.value) === "") {
        return;
    }
    todoManager.addTodoItem(input.value);
});
