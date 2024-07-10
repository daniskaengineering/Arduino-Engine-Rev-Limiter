<a name="readme-top"></a>
<br />
<div align="center">
  <h3 align="center">Small Engine Rev Limiter</h3>

  <p align="center">
    A simple Arduino based rev limiter built for a lawn mower. 
    <br />
    <a href="https://daniskaengineering.com/projects/engineering/mow-kart/">View Project</a>
  </p>
</div>



<!-- TABLE OF CONTENTS -->
<details>
  <summary>Table of Contents</summary>
  <ol>
    <li>
      <a href="#about-the-project">About The Project</a>
      <ul>
        <li><a href="#built-with">Built With</a></li>
      </ul>
    </li>
    <li>
      <ul>
        <li><a href="#prerequisites">Prerequisites</a></li>
        <li><a href="#installation">Installation</a></li>
      </ul>
    </li>
    <li><a href="#usage">Usage</a></li>
    <li><a href="#contributing">Contributing</a></li>
    <li><a href="#license">License</a></li>
    <li><a href="#contact">Contact</a></li>
    <li><a href="#acknowledgments">Acknowledgments</a></li>
  </ol>
</details>



<!-- ABOUT THE PROJECT -->
## About The Project

This is a simple rev limiter for a motor. This was built and tested with a 16HP Briggs & Stratton single cylinder engine. 
The pulses from the alternator are used to determine the RPM of the engine and the magneto bypass is grounded to cut the ignition. 
A redline can be set in code or with a potentiometer. The application for this is a flame kit for a lawn mower. 
The rev limiter can cut the ignition at high RPMs to allow unburnt fuel to travel out the exhaust. If a spark plug is installed at the end of the tail pipe, this unburnt fuel can be ignited, creating flames out the exhuast. 

<p align="right">(<a href="#readme-top">back to top</a>)</p>

### Built With

This section should list any major frameworks/libraries used to bootstrap your project. Leave any add-ons/plugins for the acknowledgements section. Here are a few examples.

* [![FreeRTOS][FreeRTOS-url]

<p align="right">(<a href="#readme-top">back to top</a>)</p>

### Installation

1. Build the hardware
2. Flash to Arduino

<p align="right">(<a href="#readme-top">back to top</a>)</p>

<!-- USAGE EXAMPLES -->
## Usage

Use this space to show useful examples of how a project can be used. Additional screenshots, code examples and demos work well in this space. You may also link to more resources.

_For more examples, please refer to the [Documentation](https://example.com)_

<p align="right">(<a href="#readme-top">back to top</a>)</p>

<!-- CONTRIBUTING -->
## Contributing

Contributions are what make the open source community such an amazing place to learn, inspire, and create. Any contributions you make are **greatly appreciated**.

If you have a suggestion that would make this better, please fork the repo and create a pull request. You can also simply open an issue with the tag "enhancement".
Don't forget to give the project a star!

1. Fork the Project
2. Create your Feature Branch (`git checkout -b feature/AmazingFeature`)
3. Commit your Changes (`git commit -m 'Add some AmazingFeature'`)
4. Push to the Branch (`git push origin feature/AmazingFeature`)
5. Open a Pull Request

<p align="right">(<a href="#readme-top">back to top</a>)</p>

<!-- LICENSE -->
## License

Distributed under the MIT License. See `LICENSE.txt` for more information.

<p align="right">(<a href="#readme-top">back to top</a>)</p>

## Contact

Taylor Daniska - taylor@daniskaengineering.com

<p align="right">(<a href="#readme-top">back to top</a>)</p>

<!-- ACKNOWLEDGMENTS -->
## Acknowledgments

* [FreeRTOS]([https://choosealicense.com](https://wiki.seeedstudio.com/Software-FreeRTOS/))
* [Seeeduino]([https://www.webpagefx.com/tools/emoji-cheat-sheet](https://wiki.seeedstudio.com/))

<p align="right">(<a href="#readme-top">back to top</a>)</p>

[FreeRTOS-url]: https://wiki.seeedstudio.com/Software-FreeRTOS/
