from flask import Flask, render_template, url_for, flash, redirect
from forms import RegistrationForm, LoginForm
from flask_sqlalchemy import SQLAlchemy

app = Flask(__name__)
app.config['SECRET_KEY'] = '22ec47e954df983f8e695832d85b70ac'

trips = [
    {
        'location': 'Plitvice',
        'Author': 'Ivan Horvat',
        'date_created': '1.2.2019',
        'transport': 'Bus',
        'spaces_available': '25',
        'start_date': '10.2.2019',
        'price': '1200'
    },
    {
        'location': 'kornati',
        'Author': 'Marko Horvat',
        'date_created': '3.2.2019',
        'transport': 'Bus',
        'spaces_available': '25',
        'start_date': '15.2.2019',
        'price': '1450'
    }
]


@app.route("/")
@app.route("/home")
def home():
    return render_template('home.html', trips=trips)


@app.route("/about")
def about():
    return render_template('about.html', title='About')


@app.route("/travelers")
def travelers():
    return render_template('travelers.html', title='Travelers')


@app.route("/register", methods=['GET', 'POST'])
def register():
    form = RegistrationForm()
    if form.validate_on_submit():       # ako registracija uspije (sva polja su popunjena ispravno)
        flash(f'Account created for {form.username.data}!', 'success')
        return redirect(url_for('home'))
    return render_template('register.html', title='Register', form=form)


@app.route("/login", methods=['GET', 'POST'])
def login():
    form = LoginForm()
    return render_template('login.html', title='Login', form=form)


if __name__ == '__main__':
    app.run(debug=True)
