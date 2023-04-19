import subprocess
import os

def test_write_and_read_text(language, text):
    # Define the input lines for the C++ program
    input_lines = [
        'file.txt',
        'w',
        text,
        'y',
        'file.txt',
        'r'
    ]

    # Run the C++ program and pass the input lines as input
    process = subprocess.Popen(['bin/main_RAII'], stdin=subprocess.PIPE, stdout=subprocess.PIPE, stderr=subprocess.PIPE)
    stdout, stderr = process.communicate('\n'.join(input_lines).encode())

    # Assert that the file was written successfully
    with open('file.txt', 'r', encoding='utf-8') as f:
        assert f.read() == text

    # Assert that the file does not exist before trying to read from it
    assert not os.path.exists('file.txt'), 'File should not exist before reading from it'

    # Output success message
    print(f'Test for writing and checking text in {language} passed successfully.')

#original
def test_write_and_read_text_original(language, text):
    
    input_lines = [
        'file.txt',
        'w',
        text,
        'y',
        'file.txt',
        'r'
    ]

    
    process = subprocess.Popen(['bin/main_RAII'], stdin=subprocess.PIPE, stdout=subprocess.PIPE, stderr=subprocess.PIPE)
    stdout, stderr = process.communicate('\n'.join(input_lines).encode())

    
    with open('file.txt', 'r', encoding='utf-8') as f:
        assert f.read() == text

   
    print(f'Test for writing and reading text in {language} passed successfully.')

# Define the test cases
test_cases = [
    ('English', 'This is a test text'),
    ('French', 'Ceci est un texte de test'),
    ('Spanish', 'Este es un texto de prueba'),
    ('Russian', 'Это тестовый текст'),
    ('Chinese', '这是一个测试文本')
]

# Run the tests
for language, text in test_cases:
    test_write_and_read_text(language, text)
    test_write_and_read_text_original(language, text)



