#include "podpch.h"
#include "LayerStack.h"

namespace Pod {

	
	LayerStack::LayerStack()
	{
		m_InsertLayer = m_Layers.begin();
	}

	LayerStack::~LayerStack()
	{
		for (Layer* layer : m_Layers) {
			delete layer;
		}
	}

	void LayerStack::PushLayer(Layer* layer)
	{
		m_InsertLayer = m_Layers.emplace(m_InsertLayer, layer);
	}

	void LayerStack::PushOverlay(Layer* layer)
	{
		m_Layers.emplace_back(layer);
	}

	void LayerStack::PopLayer(Layer* layer)
	{
		auto iterate = std::find(m_Layers.begin(), m_Layers.end(), layer);
		if (iterate != m_Layers.end()) {
			m_Layers.erase(iterate);
			m_InsertLayer--;
		}
	}

	void LayerStack::PopOverlay(Layer* layer)
	{
		auto iterate = std::find(m_Layers.begin(), m_Layers.end(), layer);
		if (iterate != m_Layers.end()) {
			m_Layers.erase(iterate);
		}
	}
}