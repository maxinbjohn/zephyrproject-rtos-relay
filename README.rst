.. zephyr:code-sample:: relay
   :name: Relay
   :relevant-api: gpio_interface

   Control a Relay using the GPIO API.

Overview
********
A relay is an electromagnetic switch operated by a relatively small electric current
that can turn on or off a much larger electric current.

This Relay sample turns a relay on and off forever using the :ref:`GPIO API <gpio_api>`.

The source code shows how to:

#. Get a pin specification from the :ref:`devicetree <dt-guide>` as a
   :c:struct:`gpio_dt_spec`
#. Configure the GPIO pin as an output
#. Toggle the pin forever

.. _relay-sample-requirements:

Requirements
************

Your board must:

#. Have a Relay connected via a GPIO pin

Building and Running
********************

Build and flash Relay as follows, changing ``longan_nano`` for your board:

.. zephyr-app-commands::
   :zephyr-app: samples/basic/relay
   :board: longan_nano
   :goals: build flash
   :compact:

After flashing, the Relay will switch on and off in 5 seconds. If a runtime error occurs, the sample
exits without printing to the console.

