class Database {
    static instance = null;
    static get() {
        if (localStorage.getItem('db') === null) {
            localStorage.setItem('db', JSON.stringify([]));
        }
        if (!Database.instance) {
            Database.instance = new Database();
        }
        return Database.instance;
    }

    getTable(name) {
        const db = JSON.parse(localStorage.getItem('db'));
        return db.find(elem => elem.name === name);
    }

    createTable(name, columns, values = null) {
        const db = JSON.parse(localStorage.getItem('db'));
        if (!db.find(elem => elem.name === name)) {
            db.push({ name: name, columns: columns, values: values });
            localStorage.setItem('db', JSON.stringify(db));
            return new Table(name, columns, values);
        }
    }
}

const db = Database.get();
console.log(db);
db.createTable('Anna', ['id', 'anna', '123']);
console.log(db.getTable('Anna'));
