from django.conf.urls import url, include
from django.urls import path
from storages import views as storages_views
from users import views as users_views
from things import views as things_views
from rest_framework.routers import DefaultRouter
from rest_framework.urlpatterns import format_suffix_patterns
from drf_spectacular.views import SpectacularAPIView, SpectacularRedocView, SpectacularSwaggerView

router = DefaultRouter()
router.register(r'storages', storages_views.StorageViewset)
router.register(r'sections', storages_views.SectionViewset)
router.register(r'things', things_views.ThingViewset)
router.register(r'instances', things_views.ThingInstanceViewset)
router.register(r'category', things_views.ThingCategoryViewset)
router.register(r'users', users_views.UserViewset)

urlpatterns = [
    url(r'^api/', include(router.urls)),
    url(r'^auth/',include('djoser.urls')),
    url(r'^auth/',include('djoser.urls.jwt')),
    path('api/schema/', SpectacularAPIView.as_view(), name='schema'),
    path('api/schema/redoc/', SpectacularRedocView.as_view(url_name='schema'), name='redoc'),
]   