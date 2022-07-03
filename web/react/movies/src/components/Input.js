function Input(props) {
    return (
        <div>
            <input
                type={props.type}
                value={props.value}
                placeholder={props.placeholder}
                onChange={props.onChange}
                id="input-field"
            />
        </div>
  );
}

export default Input;