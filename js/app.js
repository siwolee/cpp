const $ = document.querySelector;
const todoInput = $(".todo-input");
const todoButton = $(".todo-button");
const todoList = $(".todo-list");

todoButton.addEventListener("click", addTodo);

function addTodo(event){
    //Prevent form from submitting
    event.preventDefault();
}