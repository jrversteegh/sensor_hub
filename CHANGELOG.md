# Changelog
All notable changes to this project will be documented in this file.

The format is based on [Keep a Changelog](http://keepachangelog.com/en/1.0.0/)
and this project adheres to [Semantic Versioning](http://semver.org/spec/v2.0.0.html).


## [0.4.8] - Unreleased

## [0.4.6] - 2019-10-02

### Fixed
- Modbus issues

### Added
- Dummy devices for testing

## [0.4.4] - 2019-09-12

### Changed
- Some refactors

## [0.4.2] - 2019-09-10

### Added
- Add ublox device

## [0.3.4] - 2018-10-19

### Fixed
- Take device out of NMEA mode on initialization

- Somewhat extended logging


## [0.3.2] - 2018-10-09

### Fixed
- Issue with incorrect free acceleration due to setting of EnableAHS


## [0.3.0] - 2018-09-27

Initial release

### Added
- Statistics and acceleration peak processor
- Modified Xsens initialization
- Modbus server

### Known issues
- Manual is still very bare
- Xsens initialization is shaky. Device hangs sometimes and requires power cycle
- Xsens MRU Free Acceleration values are pretty useless. Will probably require dedicated processor


## [0.1.2] - 2018-09-13

### Added
- This new changelog file.
- Xsens USB device logging to file
- HTTP service (for REST later)
- Configuration by file
- User manual

## [0.1.0] - 2018-07-21

### Added
- Initial files for the project

### Changed
- Everything

### Deprecated
- Nothing

### Removed
- Nothing

### Fixed
- Everything

### Security
- None
