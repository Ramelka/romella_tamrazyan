function Button(props) {
    return (
        <button type={props.type} onClick={props.buttonClick}>{props.buttonText}</button>
    );
}

export default Button;