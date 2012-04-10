/*
 * This file is part of python-emqtt.
 *
 * python-emqtt is free software: you can redistribute it and/or modify
 * it under the terms of the GNU Lesser General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * python-emqtt is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with python-emqtt.  If not, see <http://www.gnu.org/licenses/>.
 *
 *
 * Copyright 2012 Vicente Ruiz Rodríguez <vruiz2.0@gmail.com>. All rights reserved.
 *
 */

#include <Python.h>
#include <libemqtt.h>
#include <python-mqtt_packet.h>


PyObject* MqttPacket_init(MqttPacket* self, PyObject* args, PyObject* kwargs)
{
	static char* kwlist[] = {"data", NULL};

	char* data = NULL;

	if(!PyArg_ParseTupleAndKeywords(args, kwargs, "s", kwlist, &data))
	{
		// TODO: Exception
		return NULL;
	}

	return Py_BuildValue("");
}

void MqttPacket_dealloc(MqttPacket* self)
{
	self->ob_type->tp_free((PyObject*)self);
}

static PyMemberDef MqttPacket_members[] = {
	{ NULL }
};

static PyMethodDef MqttPacket_methods[] = {
	{ NULL }
};

PyTypeObject MqttPacketType = {
	PyObject_HEAD_INIT(NULL)
	0,											/* ob_size */
	"libemqtt.MqttPacket",						/* tp_name */
	sizeof(MqttPacket),							/* tp_basicsize */
	0,											/* tp_itemsize */
	(destructor)MqttPacket_dealloc,				/* tp_dealloc */
	0,											/* tp_print*/
	0,											/* tp_getattr */
	0,											/* tp_setattr */
	0,											/* tp_compare */
	0,											/* tp_repr */
	0,											/* tp_as_number */
	0,											/* tp_as_sequence */
	0,											/* tp_as_mapping */
	0,											/* tp_hash */
	0,											/* tp_call */
	0,											/* tp_str */
	0,											/* tp_getattro */
	0,											/* tp_setattro */
	0,											/* tp_as_buffer */
	Py_TPFLAGS_DEFAULT | Py_TPFLAGS_BASETYPE,	/* tp_flags*/
	"MqttPacket objects",						/* tp_doc */
	0,											/* tp_traverse */
	0,											/* tp_clear */
	0,											/* tp_richcompare */
	0,											/* tp_weaklistoffset */
	0,											/* tp_iter */
	0,											/* tp_iternext */
	MqttPacket_methods,							/* tp_methods */
	MqttPacket_members,							/* tp_members */
	0,											/* tp_getset */
	0,											/* tp_base */
	0,											/* tp_dict */
	0,											/* tp_descr_get */
	0,											/* tp_descr_set */
	0,											/* tp_dictoffset */
	(initproc)MqttPacket_init,					/* tp_init */
	0,											/* tp_alloc */
	0,											/* tp_new */
};