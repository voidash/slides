
interface TodoItem {
  id: number;
  text: string;
  completed: boolean;
}

type TodoList = TodoItem[];

class LocalStorageManager {
  private storageKey: string;

  constructor(storageKey: string) {
    this.storageKey = storageKey;
  }

  get(): TodoList {
    const storedList = window.localStorage.getItem(this.storageKey);
    return storedList ? JSON.parse(storedList) : [];
  }

  set(todoList: TodoList) {
    console.log("setting");
    window.localStorage.setItem(this.storageKey, JSON.stringify(todoList));
  }
}

class TodoListManager {
  private todoList: TodoList;
  private storageManager: LocalStorageManager;

  constructor(manager: LocalStorageManager) {
    this.todoList = manager.get();
    this.storageManager = manager;
  }

  addTodoItem(text: string) {
    const newTodoItem: TodoItem = {
      id: Date.now(),
      text,
      completed: false,
    };

    this.todoList.push(newTodoItem);
    this.storageManager.set(this.todoList);

    renderDom(this);
  }

  deleteTodoItem(id: number) {
    this.todoList = this.todoList.filter((todoItem) => todoItem.id !== id);
    this.storageManager.set(this.todoList);
    renderDom(this);
  }

  completeTodoItem(id: number) {
    this.todoList = this.todoList.map((todoItem) => {
      if (todoItem.id === id) {
        todoItem.completed = true;
      }
      return todoItem;
    });
    this.storageManager.set(this.todoList);
    renderDom(this);
  }

  getAllTodoItems(): TodoList {
    return this.todoList;
  }
}

function renderDom(listManager: TodoListManager) {
  let parent = document.querySelector("#todo-cards") as HTMLDivElement;
 
  parent.innerHTML = "";

  let toRender = listManager.getAllTodoItems().map((todo) => {

    let card = document.createElement("div");
    card.setAttribute("id", "todo-card");

    let description = document.createElement("span");
    description.appendChild(document.createTextNode(todo.text));
    if (todo.completed) {
      description.style.textDecoration = "line-through";
    }

    let deleteButton = document.createElement("button");
    deleteButton.appendChild(document.createTextNode("delete"));
    deleteButton.addEventListener("click", (_) => {
      listManager.deleteTodoItem(todo.id);
    });

    let completeButton = document.createElement("button");
    completeButton.appendChild(document.createTextNode("completed?"));
    completeButton.addEventListener("click", (_) => {
      listManager.completeTodoItem(todo.id);
    });

    card.appendChild(description);
    card.appendChild(deleteButton);
    card.appendChild(completeButton);

    return card;
  });

  toRender.map((element) => parent?.appendChild(element));
}

let storageManager = new LocalStorageManager("todo-lists");
let todoManager = new TodoListManager(storageManager);

renderDom(todoManager);

let submit = document.querySelector("#add");
document.querySelector("#add")?.addEventListener("click", (_) => {
  let input = document.querySelector("#todo-element") as HTMLInputElement;
  if (input?.value === "") {
    return;
  }
  todoManager.addTodoItem(input.value);
});
