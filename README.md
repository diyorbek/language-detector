# language-detector

The program detects the language of a given text by its character frequency. It works based on a 1-layer neural net.

Currently there are only 3 languages (English, German, Polish). But it can be extended simply by adding more language samples to the `data` folder.

**Note:** Only ASCII latin characters are supported!

## Build

In order to build the app, run the build script:

```bash
# You might need to change the permisions first
chmod +x ./build

./build
```
